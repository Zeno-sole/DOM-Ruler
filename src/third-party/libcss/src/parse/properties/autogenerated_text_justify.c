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

    This file is part of DOM Ruler. DOM Ruler is a library to
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

/*
 * This file was generated by LibCSS gen_parser 
 * 
 * Generated from:
 *
 * text_justify:CSS_PROP_TEXT_JUSTIFY IDENT:( INHERIT: AUTO:0,TEXT_JUSTIFY_AUTO NONE:0,TEXT_JUSTIFY_NONE INTER_WORD:0,TEXT_JUSTIFY_INTER_WORD INTER_IDEOGRAPH:0,TEXT_JUSTIFY_INTER_IDEOGRAPH INTER_CLUSTER:0,TEXT_JUSTIFY_INTER_CLUSTER DISTRIBUTE:0,TEXT_JUSTIFY_DISTRIBUTE KASHIDA:0,TEXT_JUSTIFY_KASHIDA IDENT:)
 * 
 * Copyright (C) 2021 Beijing FMSoft Technologies Co., Ltd.
 */

#include <assert.h>
#include <string.h>

#include "bytecode/bytecode.h"
#include "bytecode/opcodes.h"
#include "parse/properties/properties.h"
#include "parse/properties/utils.h"

/**
 * Parse text_justify
 *
 * \param c	  Parsing context
 * \param vector  Vector of tokens to process
 * \param ctx	  Pointer to vector iteration context
 * \param result  resulting style
 * \return CSS_OK on success,
 *	   CSS_NOMEM on memory exhaustion,
 *	   CSS_INVALID if the input is not valid
 *
 * Post condition: \a *ctx is updated with the next token to process
 *		   If the input is invalid, then \a *ctx remains unchanged.
 */
css_error css__parse_text_justify(css_language *c,
		const parserutils_vector *vector, int *ctx,
		css_style *result)
{
	int orig_ctx = *ctx;
	css_error error;
	const css_token *token;
	bool match;

	token = parserutils_vector_iterate(vector, ctx);
	if ((token == NULL) || ((token->type != CSS_TOKEN_IDENT))) {
		*ctx = orig_ctx;
		return CSS_INVALID;
	}

	if ((lwc_string_caseless_isequal(token->idata, c->strings[INHERIT], &match) == lwc_error_ok && match)) {
			error = css_stylesheet_style_inherit(result, CSS_PROP_TEXT_JUSTIFY);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[AUTO], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_TEXT_JUSTIFY, 0,TEXT_JUSTIFY_AUTO);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[NONE], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_TEXT_JUSTIFY, 0,TEXT_JUSTIFY_NONE);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[INTER_WORD], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_TEXT_JUSTIFY, 0,TEXT_JUSTIFY_INTER_WORD);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[INTER_IDEOGRAPH], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_TEXT_JUSTIFY, 0,TEXT_JUSTIFY_INTER_IDEOGRAPH);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[INTER_CLUSTER], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_TEXT_JUSTIFY, 0,TEXT_JUSTIFY_INTER_CLUSTER);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[DISTRIBUTE], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_TEXT_JUSTIFY, 0,TEXT_JUSTIFY_DISTRIBUTE);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[KASHIDA], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_TEXT_JUSTIFY, 0,TEXT_JUSTIFY_KASHIDA);
	} else {
		error = CSS_INVALID;
	}

	if (error != CSS_OK)
		*ctx = orig_ctx;
	
	return error;
}

