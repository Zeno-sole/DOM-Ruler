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

/*
 * This file was generated by LibCSS gen_parser 
 * 
 * Generated from:
 *
 * marker_mid:CSS_PROP_MARKER_MID IDENT:( INHERIT: NONE:0,MARKER_MID_NONE IDENT:) URI:MARKER_MID_URI
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
 * Parse marker_mid
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
css_error css__parse_marker_mid(css_language *c,
		const parserutils_vector *vector, int *ctx,
		css_style *result)
{
	int orig_ctx = *ctx;
	css_error error;
	const css_token *token;
	bool match;

	token = parserutils_vector_iterate(vector, ctx);
	if ((token == NULL) || ((token->type != CSS_TOKEN_IDENT) && (token->type != CSS_TOKEN_URI))) {
		*ctx = orig_ctx;
		return CSS_INVALID;
	}

	if ((token->type == CSS_TOKEN_IDENT) && (lwc_string_caseless_isequal(token->idata, c->strings[INHERIT], &match) == lwc_error_ok && match)) {
			error = css_stylesheet_style_inherit(result, CSS_PROP_MARKER_MID);
	} else if ((token->type == CSS_TOKEN_IDENT) && (lwc_string_caseless_isequal(token->idata, c->strings[NONE], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_MARKER_MID, 0,MARKER_MID_NONE);
	} else if (token->type == CSS_TOKEN_URI) {
		lwc_string *uri = NULL;
		uint32_t uri_snumber;

		error = c->sheet->resolve(c->sheet->resolve_pw,
				c->sheet->url,
				token->idata, &uri);
		if (error != CSS_OK) {
			*ctx = orig_ctx;
			return error;
		}

		error = css__stylesheet_string_add(c->sheet, uri, &uri_snumber);
		if (error != CSS_OK) {
			*ctx = orig_ctx;
			return error;
		}

		error = css__stylesheet_style_appendOPV(result, CSS_PROP_MARKER_MID, 0, MARKER_MID_URI);
		if (error != CSS_OK) {
			*ctx = orig_ctx;
			return error;
		}

		error = css__stylesheet_style_append(result, uri_snumber);
	} else {
		error = CSS_INVALID;
	}

	if (error != CSS_OK)
		*ctx = orig_ctx;
	
	return error;
}

