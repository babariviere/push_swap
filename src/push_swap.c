/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:12:51 by briviere          #+#    #+#             */
/*   Updated: 2018/02/19 17:04:02 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	print_instrs(const t_stack *instr)
{
	size_t		idx;

	idx = 0;
	while (idx < instr->len)
	{
		write_instr(instr->data[idx]);
		ft_putchar('\n');
		idx++;
	}
}

static void	exec_swap(t_stack_hld *hld)
{
	// TODO: optimize useless repetition
	hld->instr = stack_create(hld->a->len * 10);
	sort_stack(hld);
	print_instrs(hld->instr);
	stack_delete(&hld->instr);
}

int			main(int ac, char **av)
{
	t_stack_hld	hld;
	t_stack		*a;
	t_stack		*b;

	a = 0;
	b = 0;
	if ((a = stack_from_args(ac, av, 0)) == 0)
		ft_putendl_fd("Error", 2);
	else if ((b = stack_create(a->len)) == 0)
		ft_putendl_fd("Error", 2);
	else if (stack_has_dup(a))
		ft_putendl_fd("Error", 2);
	else
	{
		hld = (t_stack_hld){a, b, 0};
		exec_swap(&hld);
	}
	stack_delete(&a);
	stack_delete(&b);
	return (0);
}
