/*
 * Copyright (C) 2021 Beijing FMSoft Technologies Co., Ltd.
 */

#include "bytecode/bytecode.h"
#include "bytecode/opcodes.h"
#include "select/propset.h"
#include "select/propget.h"
#include "utils/utils.h"

#include "select/properties/properties.h"
#include "select/properties/helpers.h"

css_error css__cascade_text_rendering(uint32_t opv, css_style *style,
		css_select_state *state)
{
	return CSS_OK;
}

css_error css__set_text_rendering_from_hint(const css_hint *hint,
		css_computed_style *style)
{
	return CSS_OK;
}

css_error css__initial_text_rendering(css_select_state *state)
{
	return CSS_OK;
}

css_error css__compose_text_rendering(const css_computed_style *parent,
		const css_computed_style *child,
		css_computed_style *result)
{
	return CSS_OK;
}

