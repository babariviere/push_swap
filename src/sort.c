/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:17:10 by briviere          #+#    #+#             */
/*   Updated: 2018/02/16 15:38:40 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

//static void	split_stack_a(t_stack *a, t_stack *b, t_stack *instr)
//{
//	int		aver;
//
//	aver = calc_average(a);
//	while (get_lower(a) <= aver)
//	{
//		while (a->data[0] > aver && a->data[a->len - 1] > aver)
//		{
//			stack_rrotate(a);
//			stack_push(instr, INSTR_RRA);
//		}
//		while (a->data[a->len - 1] <= aver)
//		{
//			stack_push(b, stack_pop(a));
//			stack_push(instr, INSTR_PB);
//		}
//		if (a->data[0] <= aver)
//		{
//			stack_rrotate(a);
//			stack_push(instr, INSTR_RRA);
//			stack_push(b, stack_pop(a));
//			stack_push(instr, INSTR_PB);
//			continue ;
//		}
//	}
//}

void		naive_sort(t_stack *a, t_stack *b, t_stack *instr)
{
	int		high;

	while (!stack_is_sort(a))
	{
		high = get_highest(a);
		while (a->data[a->len - 1] != high)
		{
			stack_rrotate(a);
			stack_push(instr, INSTR_RRA);
		}
		stack_push(b, stack_pop(a));
		stack_push(instr, INSTR_PB);
	}
	while (b->len > 0)
	{
		stack_push(a, stack_pop(b));
		stack_push(instr, INSTR_PA);
		stack_rotate(a);
		stack_push(instr, INSTR_RA);
	}
}

void		sort_stack(t_stack *a, t_stack *b, t_stack *instr)
{
	if (stack_is_sort(a) && b->len == 0)
		return ;
	//split_stack_a(a, b, instr);
	naive_sort(a, b, instr);
}
