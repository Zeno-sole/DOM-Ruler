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
 * comp_op:CSS_PROP_COMP_OP IDENT:( INHERIT: CLEAR:0,COMP_OP_CLEAR SRC:0,COMP_OP_SRC DST:0,COMP_OP_DST SRC_OVER:0,COMP_OP_SRC_OVER DST_OVER:0,COMP_OP_DST_OVER SRC_IN:0,COMP_OP_SRC_IN DST_IN:0,COMP_OP_DST_IN SRC_OUT:0,COMP_OP_SRC_OUT DST_OUT:0,COMP_OP_DST_OUT SRC_ATOP:0,COMP_OP_SRC_ATOP DST_ATOP:0,COMP_OP_DST_ATOP XOR:0,COMP_OP_XOR PLUS:0,COMP_OP_PLUS MULTIPLY:0,COMP_OP_MULTIPLY SCREEN:0,COMP_OP_SCREEN OVERLAY:0,COMP_OP_OVERLAY DARKEN:0,COMP_OP_DARKEN LIGHTEN:0,COMP_OP_LIGHTEN COLOR_DODGE:0,COMP_OP_COLOR_DODGE COLOR_BURN:0,COMP_OP_COLOR_BURN HARD_LIGHT:0,COMP_OP_HARD_LIGHT SOFT_LIGHT:0,COMP_OP_SOFT_LIGHT DIFFERENCE:0,COMP_OP_DIFFERENCE EXCLUSION:0,COMP_OP_EXCLUSION IDENT:)
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
 * Parse comp_op
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
css_error css__parse_comp_op(css_language *c,
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
			error = css_stylesheet_style_inherit(result, CSS_PROP_COMP_OP);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[CLEAR], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_CLEAR);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[SRC], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_SRC);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[DST], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_DST);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[SRC_OVER], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_SRC_OVER);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[DST_OVER], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_DST_OVER);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[SRC_IN], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_SRC_IN);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[DST_IN], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_DST_IN);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[SRC_OUT], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_SRC_OUT);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[DST_OUT], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_DST_OUT);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[SRC_ATOP], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_SRC_ATOP);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[DST_ATOP], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_DST_ATOP);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[XOR], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_XOR);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[PLUS], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_PLUS);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[MULTIPLY], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_MULTIPLY);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[SCREEN], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_SCREEN);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[OVERLAY], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_OVERLAY);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[DARKEN], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_DARKEN);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[LIGHTEN], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_LIGHTEN);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[COLOR_DODGE], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_COLOR_DODGE);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[COLOR_BURN], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_COLOR_BURN);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[HARD_LIGHT], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_HARD_LIGHT);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[SOFT_LIGHT], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_SOFT_LIGHT);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[DIFFERENCE], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_DIFFERENCE);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[EXCLUSION], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_COMP_OP, 0,COMP_OP_EXCLUSION);
	} else {
		error = CSS_INVALID;
	}

	if (error != CSS_OK)
		*ctx = orig_ctx;
	
	return error;
}

