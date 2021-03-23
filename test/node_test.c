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

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "hilayout.h"

void clear_private(void* data)
{
    HL_LOGW("clear_private is called|data=%p\n", data);
}

int main(int argc, char **argv)
{

    HLDomElementNode* root = hilayout_element_node_create("div");

    // test get tag name
    const char* tag_name = hilayout_element_node_get_tag_name(root);
    HL_LOGW("test|get tag name|tag=%s\n", tag_name);

    // test set attribute
    hilayout_element_node_set_attr(root, HL_ATTR_NAME, "name attribute");
    hilayout_element_node_set_attr(root, HL_ATTR_VALUE, "value attribute");
    hilayout_element_node_set_attr(root, HL_ATTR_ID, "idAttribute");
    hilayout_element_node_set_attr(root, HL_ATTR_CLASS, "classA classB classC");
    hilayout_element_node_set_attr(root, HL_ATTR_STYLE, "color=#33333; width=10px;");
    hilayout_element_node_set_attr(root, "xsm", "xsm attribute");


    // test get attribute
    const char* value = hilayout_element_node_get_attr(root, HL_ATTR_NAME);
    HL_LOGW("test|get attribute|attr=%s|value=%s\n", HL_ATTR_NAME, value);

    value = hilayout_element_node_get_attr(root, HL_ATTR_VALUE);
    HL_LOGW("test|get attribute|attr=%s|value=%s\n", HL_ATTR_VALUE, value);

    value = hilayout_element_node_get_attr(root, HL_ATTR_ID);
    HL_LOGW("test|get attribute|attr=%s|value=%s\n", HL_ATTR_ID, value);

    value = hilayout_element_node_get_attr(root, HL_ATTR_CLASS);
    HL_LOGW("test|get attribute|attr=%s|value=%s\n", HL_ATTR_CLASS, value);

    value = hilayout_element_node_get_attr(root, HL_ATTR_STYLE);
    HL_LOGW("test|get attribute|attr=%s|value=%s\n", HL_ATTR_STYLE, value);

    value = hilayout_element_node_get_attr(root, "xsm");
    HL_LOGW("test|get attribute|attr=%s|value=%s\n", "xsm", value);

    // test private data
    char buf[] = "xsm";
    hilayout_element_node_set_private_data(root, buf);
    void* data = hilayout_element_node_get_private_data(root);
    HL_LOGW("test|get private data|data=%p\n", data);

    // test content
    hilayout_element_node_set_content(root, "this is content for test.");
    value = hilayout_element_node_get_content(root);
    HL_LOGW("test|get content|content=%s\n", value);

    // output test
    const HLUsedBoxValues* box = hilayout_element_node_get_used_box_value(root);
    HL_LOGW("test|get box value|ret=%p\n", box);

    const HLUsedBackgroundValues* bg = hilayout_element_node_get_used_background_value(root);
    HL_LOGW("test|get bg value|ret=%p\n", bg);

    const HLUsedTextValues* text = hilayout_element_node_get_used_font_value(root);
    HL_LOGW("test|get text value|ret=%p\n", text);

    // test append as last child
    char name[20];
    int index = 0;
    for (index = 0; index < 10; index++)
    {
        snprintf(name, 20, "%d", index);
        HL_LOGW("\n");
        HL_LOGW("test|add node|index=%d|name=%s\n", index, name);
        HLDomElementNode* div = hilayout_element_node_create("div");
        hilayout_element_node_set_attr(div, HL_ATTR_NAME, name);
        hilayout_element_node_append_as_last_child(div, root);
    }


    hilayout_element_node_destroy(root, clear_private);
	return 0;
}

