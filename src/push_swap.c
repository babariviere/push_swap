/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:12:51 by briviere          #+#    #+#             */
/*   Updated: 2018/02/16 16:04:40 by briviere         ###   ########.fr       */
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

static void	exec_swap(t_stack *a, t_stack *b)
{
	t_stack		*instr;

	instr = stack_create(a->len * 10);
	sort_stack(a, b, instr);
	print_instrs(instr);
}

int			main(int ac, char **av)
{
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
		exec_swap(a, b);
	stack_delete(&a);
	stack_delete(&b);
	return (0);
}
