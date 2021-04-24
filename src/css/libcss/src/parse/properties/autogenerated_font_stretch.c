/*
 * This file was generated by LibCSS gen_parser 
 * 
 * Generated from:
 *
 * font_stretch:CSS_PROP_FONT_STRETCH IDENT:( INHERIT: NORMAL:0,FONT_STRETCH_NORMAL WIDER:0,FONT_STRETCH_WIDER NARROWER:0,FONT_STRETCH_NARROWER ULTRA_CONDENSED:0,FONT_STRETCH_ULTRA_CONDENSED EXTRA_CONDENSED:0,FONT_STRETCH_EXTRA_CONDENSED CONDENSED:0,FONT_STRETCH_CONDENSED SEMI_CONDENSED:0,FONT_STRETCH_SEMI_CONDENSED SEMI_EXPANDED:0,FONT_STRETCH_SEMI_EXPANDED EXPANDED:0,FONT_STRETCH_EXPANDED EXTRA_EXPANDED:0,FONT_STRETCH_EXTRA_EXPANDED ULTRA_EXPANDED:0,FONT_STRETCH_ULTRA_EXPANDED IDENT:)
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
 * Parse font_stretch
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
css_error css__parse_font_stretch(css_language *c,
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
			error = css_stylesheet_style_inherit(result, CSS_PROP_FONT_STRETCH);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[NORMAL], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_FONT_STRETCH, 0,FONT_STRETCH_NORMAL);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[WIDER], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_FONT_STRETCH, 0,FONT_STRETCH_WIDER);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[NARROWER], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_FONT_STRETCH, 0,FONT_STRETCH_NARROWER);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[ULTRA_CONDENSED], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_FONT_STRETCH, 0,FONT_STRETCH_ULTRA_CONDENSED);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[EXTRA_CONDENSED], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_FONT_STRETCH, 0,FONT_STRETCH_EXTRA_CONDENSED);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[CONDENSED], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_FONT_STRETCH, 0,FONT_STRETCH_CONDENSED);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[SEMI_CONDENSED], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_FONT_STRETCH, 0,FONT_STRETCH_SEMI_CONDENSED);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[SEMI_EXPANDED], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_FONT_STRETCH, 0,FONT_STRETCH_SEMI_EXPANDED);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[EXPANDED], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_FONT_STRETCH, 0,FONT_STRETCH_EXPANDED);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[EXTRA_EXPANDED], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_FONT_STRETCH, 0,FONT_STRETCH_EXTRA_EXPANDED);
	} else if ((lwc_string_caseless_isequal(token->idata, c->strings[ULTRA_EXPANDED], &match) == lwc_error_ok && match)) {
			error = css__stylesheet_style_appendOPV(result, CSS_PROP_FONT_STRETCH, 0,FONT_STRETCH_ULTRA_EXPANDED);
	} else {
		error = CSS_INVALID;
	}

	if (error != CSS_OK)
		*ctx = orig_ctx;
	
	return error;
}

