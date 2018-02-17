/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:17:10 by briviere          #+#    #+#             */
/*   Updated: 2018/02/17 19:07:14 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

//void		naive_sort(t_stack *a, t_stack *b, t_stack *instr)
//{
//	int		high;
//
//	while (!stack_is_sort(a))
//	{
//		high = get_highest(a);
//		while (a->data[a->len - 1] != high)
//		{
//			stack_rrotate(a);
//			stack_push(instr, INSTR_RRA);
//		}
//		stack_push(b, stack_pop(a));
//		stack_push(instr, INSTR_PB);
//	}
//	while (b->len > 0)
//	{
//		stack_push(a, stack_pop(b));
//		stack_push(instr, INSTR_PA);
//		stack_rotate(a);
//		stack_push(instr, INSTR_RA);
//	}
//}

// TODO: recursive to estimate best move
static void	test_sort(t_stack_hld *hld)
{
	while (!stack_is_sort(hld->a))
	{
		if (stack_cmp_top(hld->a) > 0)
			apply_instr_and_save(hld, INSTR_SA);
		else
			apply_instr_and_save(hld, INSTR_PB);
		if (stack_cmp_bot_top(hld->a) < 0)
			apply_instr_and_save(hld, INSTR_RA);
		if (stack_cmp_bot_top(hld->b) > 0)
			apply_instr_and_save(hld, INSTR_RB);
		if (stack_cmp_top(hld->b) < 0)
			apply_instr_and_save(hld, INSTR_SB);
		if (stack_cmp_bot(hld->a) < 0)
		{
			apply_instr_and_save(hld, INSTR_RRA);
			apply_instr_and_save(hld, INSTR_RRA);
			apply_instr_and_save(hld, INSTR_SA);
			apply_instr_and_save(hld, INSTR_RA);
			apply_instr_and_save(hld, INSTR_RA);
		}
		if (stack_cmp_bot(hld->b) > 0)
		{
			apply_instr_and_save(hld, INSTR_RRB);
			apply_instr_and_save(hld, INSTR_RRB);
			apply_instr_and_save(hld, INSTR_SB);
			apply_instr_and_save(hld, INSTR_RB);
			apply_instr_and_save(hld, INSTR_RB);
		}
	}
	while (hld->b->len > 0)
	{
		apply_instr_and_save(hld, INSTR_PA);
		if (stack_cmp_top(hld->a) > 0)
			apply_instr_and_save(hld, INSTR_SA);
	}
}

void		sort_stack(t_stack_hld *hld)
{
	if (stack_is_sort(hld->a) && hld->b->len == 0)
		return ;
	//split_stack_a(a, b, instr);
	//naive_sort(a, b, instr);
	//small_stack_sort(a, b, instr);
	test_sort(hld);
	sort_stack(hld);
}
