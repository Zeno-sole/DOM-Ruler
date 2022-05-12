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

    This file is part of HiDOMLayout. hiDOMLayout is a library to
    maintain a DOM tree, lay out and stylize the DOM nodes by
    using CSS (Cascaded Style Sheets).

    Copyright (C) 2021 Beijing FMSoft Technologies Co., Ltd.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General License for more details.

    You should have received a copy of the GNU Lesser General License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Or,

    As this program is a library, any link to this program must follow
    GNU Lesser General License version 3 (LGPLv3). If you cannot accept
    LGPLv3, you need to be licensed from FMSoft.

    If you have got a commercial license of this program, please use it
    under the terms and conditions of the commercial license.

    For more information about the commercial license, please refer to
    <http://www.minigui.com/blog/minigui-licensing-policy/>.

 \endverbatim
 */


#include "hidomlayout.h"
#include "layout.h"

#include "utils.h"
#include "select.h"

#include "hl_dom_element_node.h"

#include <stdio.h>
#include <stdlib.h>

static inline
bool hl_verify_handler(hidomlayout_node_op *op)
{
    if (!op || !op->set_attach || !op->get_attach
            || !op->set_parent || !op->get_parent
            || !op->first_child || !op->next
            || !op->is_root) {
        return false;
    }
    return true;
}

int hidomlayout_layout(HLMedia *media, HLCSS *css, void *root,
        hidomlayout_node_op *op)
{
    if (!media || !css || !root || !hl_verify_handler(op)) {
        HL_LOGE("%s|media=%p|root=%p|css=%p|style_sheet=%p|param error\n",
                __func__, media, root, css, css->sheet);
        return HILAYOUT_BADPARM;
    }

    return 0;
}

int hilayout_do_layout(HLMedia* media, HLCSS* css, HLDomElementNode *root)
{
    return 0;
}

