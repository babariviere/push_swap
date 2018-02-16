/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:12:39 by briviere          #+#    #+#             */
/*   Updated: 2018/02/16 14:35:31 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	exec_checker(t_stack *a, t_stack *b)
{
	t_instr		instr;

	while ((instr = read_instr()) > 0)
		apply_instr(a, b, instr);
	if (instr == INSTR_INV)
		ft_putendl_fd("Error", 2);
	else if (!stack_is_sort(a) || b->len > 0)
		ft_putendl("KO");
	else
		ft_putendl("OK");
}

int		main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;

	a = 0;
	b = 0;
	if ((a = stack_from_args(ac, av)) == 0)
		ft_putendl_fd("Error", 2);
	else if ((b = stack_create(a->len)) == 0)
		ft_putendl_fd("Error", 2);
	else if (stack_has_dup(a))
		ft_putendl_fd("Error", 2);
	else
		exec_checker(a, b);
	stack_delete(&a);
	stack_delete(&b);
	return (0);
}
