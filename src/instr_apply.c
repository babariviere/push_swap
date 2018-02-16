/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:45:49 by briviere          #+#    #+#             */
/*   Updated: 2018/02/16 16:46:28 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void		apply_instr_push(t_stack *a, t_stack *b, t_instr instr)
{
	if (instr == INSTR_PA)
	{
		if (b->len == 0)
			return ;
		stack_push(a, stack_pop(b));
	}
	if (instr == INSTR_PB)
	{
		if (a->len == 0)
			return ;
		stack_push(b, stack_pop(a));
	}
}

void			apply_instr(t_stack *a, t_stack *b, t_instr instr)
{
	if (instr == INSTR_SA || instr == INSTR_SS)
		stack_swap(a);
	if (instr == INSTR_SB || instr == INSTR_SS)
		stack_swap(b);
	apply_instr_push(a, b, instr);
	if (instr == INSTR_RA || instr == INSTR_RR)
		stack_rotate(a);
	if (instr == INSTR_RB || instr == INSTR_RR)
		stack_rotate(b);
	if (instr == INSTR_RRA || instr == INSTR_RRR)
		stack_rrotate(a);
	if (instr == INSTR_RRB || instr == INSTR_RRR)
		stack_rrotate(b);
}

void			apply_instr_and_save(t_stack *a, t_stack *b, t_instr tmp,
		t_stack *instr)
{
	apply_instr(a, b, tmp);
	stack_push(instr, tmp);
}
