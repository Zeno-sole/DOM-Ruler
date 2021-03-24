/////////////////////////////////////////////////////////////////////////////// //
//                          IMPORTANT NOTICE
//
// The following open source license statement does not apply to any
// entity in the Exception List published by FMSoft.
//
// For more information, please visit:
//
// https://www.fmsoft.cn/exception-list
//
//////////////////////////////////////////////////////////////////////////////
/**
 \verbatim

    This file is part of HybridOS, a developing operating system based on
    MiniGUI. HybridOs will support embedded systems and smart IoT devices.

    Copyright (C) 2020 Beijing FMSoft Technologies Co., Ltd.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Or,

    As this program is a library, any link to this program must follow
    GNU General Public License version 3 (GPLv3). If you cannot accept
    GPLv3, you need to be licensed from FMSoft.

    If you have got a commercial license of this program, please use it
    under the terms and conditions of the commercial license.

    For more information about the commercial license, please refer to
    <http://www.minigui.com/blog/minigui-licensing-policy/>.

 \endverbatim
 */


#include "layout.h"
#include "select.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif

#ifndef min
#define min(a,b) ((a)<(b)?(a):(b))
#endif

int calcNodeWidthHeight(HLDomElementNode *node, int containerWidth, int containerHeight, int childWidth, int childHeight)
{
    node->box_values.w = 10 + childWidth;
    node->box_values.h = 10 + childHeight;
    return 0;
}

int layout_node(HLDomElementNode *node, int x, int y, int widthLimit, int heightLimit, int *width, int *height, int level)
{
    for (int i = 0; i < level; i++)
    {
        fprintf(stderr, "    ");
    }

    fprintf(stderr, "node|tag=%s|id=%s\n", node->tag, node->attr[HL_ATTR_NAME_ID]);
    if (node == NULL)
    {
        return 0;
    }

    node->box_values.x = x;
    node->box_values.y = y;

    int childWidth = 0;
    int childHeight = 0;
    if (node->first_child)
    {
        switch (node->layout_type)
        {
            case LAYOUT_BLOCK:
                layout_child_node_block(node, x, y, widthLimit, heightLimit, &childWidth, &childHeight, level);
                break;

            case LAYOUT_INLINE_BLOCK:
                layout_child_node_inline_block(node, x, y, widthLimit, heightLimit, &childWidth, &childHeight, level);
                break;

            default:
                layout_child_node_block(node, x, y, widthLimit, heightLimit, &childWidth, &childHeight, level);
                break;
        }
    }

    calcNodeWidthHeight(node, widthLimit, heightLimit, childWidth, childHeight);
    *width = node->box_values.w;
    *height = node->box_values.h;
    for (int i = 0; i < level; i++)
    {
        fprintf(stderr, "    ");
    }
    fprintf(stderr, "node|tag=%s|id=%s|(%f, %f, %f, %f)\n", node->tag, node->attr[HL_ATTR_NAME_ID], node->box_values.x, node->box_values.y, node->box_values.w, node->box_values.h);
    return 0;
}

/** Media DPI in fixed point units: defaults to 96, same as nscss_baseline_pixel_density */
//css_fixed default_hl_css_media_dpi = F_96;
int hl_default_media_dpi = 96;

/** Medium screen density for device viewing distance. */
//css_fixed default_hl_css_baseline_pixel_density = F_96;
int hl_default_css_baseline_pixel_density = 96;

typedef struct HLContext_ {
    HLMedia* media;
    HLCSS* css;
    css_fixed hl_css_media_dpi;
    css_fixed hl_css_baseline_pixel_density;
} HLContext;


/**
 * Convert css pixels to physical pixels.
 *
 * \param[in] css_pixels  Length in css pixels.
 * \return length in physical pixels
 */
static inline css_fixed hl_css_pixels_css_to_physical(HLContext* ctx, css_fixed css_pixels)
{
    return FDIV(FMUL(css_pixels, ctx->hl_css_media_dpi), ctx->hl_css_baseline_pixel_density);
}

/**
 * Convert physical pixels to css pixels.
 *
 * \param[in] physical_pixels  Length in physical pixels.
 * \return length in css pixels
 */
static inline css_fixed hl_css_pixels_physical_to_css(HLContext* ctx, css_fixed physical_pixels)
{
    return FDIV(FMUL(physical_pixels, ctx->hl_css_baseline_pixel_density), ctx->hl_css_media_dpi);
}

int hl_set_media_dpi(HLContext* ctx, int dpi)
{
    if (dpi < 72 || dpi > 250) {
        int bad = dpi;
        dpi = min(max(dpi, 72), 250);
        HL_LOGW("%s|invalid dpi=%d|change to dpi=%d\n", __func__, bad, dpi);
    }
    ctx->hl_css_media_dpi = INTTOFIX(dpi);
    return HILAYOUT_OK;
}

int hl_set_baseline_pixel_density(HLContext* ctx, int density)
{
    if (density < 72 || density > 250) {
        int bad = density;
        density = min(max(density, 72), 250);
        HL_LOGW("%s|invalid density=%d|change to density=%d\n", __func__, bad, density);
    }
    ctx->hl_css_baseline_pixel_density = INTTOFIX(density);
    return HILAYOUT_OK;
}

int _hilayout_select_child_style(const css_media* media, css_select_ctx* select_ctx, HLDomElementNode* node)
{
    int ret = _hilayout_select_node_style(media, select_ctx, node);
    if (ret != HILAYOUT_OK)
    {
        return ret;
    }
    HLDomElementNode* child = node->first_child;
    while(child)
    {
        ret = _hilayout_select_child_style(media, select_ctx, child);
        if (ret != HILAYOUT_OK)
        {
            return ret;
        }
        child = child->next;
    }
    return HILAYOUT_OK;
}

int _hilayout_calc_z_index(HLDomElementNode *node)
{
    int32_t index = 0;
    int8_t val = css_computed_z_index(node->computed_style, &index);
    switch (val) {
    case CSS_Z_INDEX_INHERIT:
        HL_LOGW("calc z index|tag=%s|id=%s|name=%s|z-index=inherit\n", node->tag, node->attr[HL_ATTR_NAME_ID], node->attr[HL_ATTR_NAME_NAME]);
        break;

    case CSS_Z_INDEX_AUTO:
        HL_LOGW("calc z index||tag=%s|id=%s|name=%s|z-index=auto\n", node->tag, node->attr[HL_ATTR_NAME_ID], node->attr[HL_ATTR_NAME_NAME]);
        break;

    case CSS_Z_INDEX_SET:
        HL_LOGW("calc z index|tag=%s|id=%s|name=%s|z-index=%d\n", node->tag, node->attr[HL_ATTR_NAME_ID], node->attr[HL_ATTR_NAME_NAME], index);
        break;

    default:
        HL_LOGW("calc z index|tag=%s|id=%s|name=%s|z-index=default\n", node->tag, node->attr[HL_ATTR_NAME_ID], node->attr[HL_ATTR_NAME_NAME]);
        break;
    }
    node->box_values.z_index = index;
    return index;
}

int _hilayout_layout_node(HLDomElementNode *node, int x, int y, int container_width, int container_height, int level)
{
    if (node == NULL)
    {
        HL_LOGW("layout node|level=%d|node=%p\n", level, node);
        return HILAYOUT_OK;
    }

    HL_LOGW("layout node|level=%d|tag=%s|id=%s|name=%s|parent=%p\n", level, node->tag, node->attr[HL_ATTR_NAME_ID], node->attr[HL_ATTR_NAME_NAME], node->parent);
    node->box_values.x = x;
    node->box_values.y = y;

    if (node->parent == NULL)
    {
        node->box_values.w = container_width;
        node->box_values.h = container_height;
        _hilayout_calc_z_index(node);
    }

    int cx = x;
    int cy = y;
    int cw = container_width;
    int ch = container_height;
    int cl = level + 1;
    int node_height = 0;
    int node_width = 0;
    HLDomElementNode* child = node->first_child;
    while(child)
    {
        switch (child->layout_type)
        {
            case LAYOUT_BLOCK:
                cy = cy + node_height;
                _hilayout_layout_node(child, cx, cy, cw, ch, cl);
                node_width = node_width + child->box_values.w;
                node_height = node_height + child->box_values.h;
                break;

            case LAYOUT_INLINE_BLOCK:
                cx = cx + node_width;
                _hilayout_layout_node(child, cx, cy, cw, ch, cl);
                node_width = node_width + child->box_values.w;
                node_height = node_height + child->box_values.h;
                break;

            default:
                cy = cy + node_height;
                _hilayout_layout_node(child, cx, cy, cw, ch, cl);
                node_width = node_width + child->box_values.w;
                node_height = node_height + child->box_values.h;
                break;
        }
        child = child->next;
    }

    node->box_values.w = node_width + 10;
    node->box_values.h = node_height + 10;
    HL_LOGW("layout node|level=%d|tag=%s|id=%s|name=%s|parent=%p|w=%f|h=%f\n", level, node->tag, node->attr[HL_ATTR_NAME_ID], node->attr[HL_ATTR_NAME_NAME], node->parent, node->box_values.w, node->box_values.h);
    return HILAYOUT_OK;
}

int hilayout_do_layout(HLMedia* media, HLCSS* css, HLDomElementNode *root)
{
    if (media == NULL || root == NULL || css == NULL || css->sheet == NULL)
    {
        HL_LOGW("%s|media=%p|root=%p|css=%p|style_sheet=%p|param error\n", __func__, media, root, css, css->sheet);
        return HILAYOUT_NOMEM;
    }

	HLContext context = {
		.media = media,
		.css = css
	};
    HLContext* ctx = &context;
    hl_set_media_dpi(ctx, media->dpi > 0 ? media->dpi : hl_default_media_dpi);
    hl_set_baseline_pixel_density(ctx, media->density > 0 ? media->density : hl_default_css_baseline_pixel_density);

	css_media m;
	m.type = CSS_MEDIA_SCREEN;
    m.width  = hl_css_pixels_physical_to_css(ctx, INTTOFIX(media->width));
    m.height = hl_css_pixels_physical_to_css(ctx, INTTOFIX(media->height));

    HL_LOGD("media|param dpi=%d|density=%d|after calc inner|dpi=0x%x|density=0x%x\n",
            media->dpi, media->density, ctx->hl_css_media_dpi, ctx->hl_css_baseline_pixel_density);
    HL_LOGD("media|param w=%d|h=%d|after calc inner|w=%d|h=%d|to physical|w=%d|h=%d\n",
            media->width, media->height, m.width, m.height, FIXTOINT(hl_css_pixels_css_to_physical(ctx, m.width)), FIXTOINT(hl_css_pixels_css_to_physical(ctx, m.height)));

    // create css select context
    css_select_ctx* select_ctx = _hilayout_css_select_ctx_create(css);

    int ret = _hilayout_select_child_style(&m, select_ctx, root);
    if (ret != HILAYOUT_OK)
    {
        HL_LOGW("%s|select child style failed.|code=%d\n", __func__, ret);
        _hilayout_css_select_ctx_destroy(select_ctx);
        return ret;
    }

    _hilayout_layout_node(root, 0, 0, media->width, media->height, 0);
    _hilayout_css_select_ctx_destroy(select_ctx);
    return ret;
}

