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

css_error css__cascade_comp_op(uint32_t opv, css_style *style,
		css_select_state *state)
{
	return CSS_OK;
}

css_error css__set_comp_op_from_hint(const css_hint *hint,
		css_computed_style *style)
{
	return CSS_OK;
}

css_error css__initial_comp_op(css_select_state *state)
{
	return CSS_OK;
}

css_error css__compose_comp_op(const css_computed_style *parent,
		const css_computed_style *child,
		css_computed_style *result)
{
	return CSS_OK;
}

