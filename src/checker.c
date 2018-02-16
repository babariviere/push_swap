/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:12:39 by briviere          #+#    #+#             */
/*   Updated: 2018/02/16 13:45:52 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	print_stack(const t_stack *stack)
{
	size_t	idx;

	idx = stack->len;
	while (idx-- > 0)
	{
		ft_putnbr(stack->data[idx]);
		ft_putchar('\n');
	}
}

int		main(int ac, char **av)
{
	t_stack		*st;

	st = stack_from_args(ac, av);
	print_stack(st);
	ft_putendl("swap");
	stack_swap(st);
	print_stack(st);
	ft_putendl("rotate");
	stack_rotate(st);
	print_stack(st);
	ft_putendl("rotate reverse");
	stack_rrotate(st);
	print_stack(st);
	ft_putendl("is sort");
	ft_putnbr(stack_is_sort(st));
	ft_putchar('\n');
	ft_putendl("swap");
	stack_swap(st);
	print_stack(st);
	ft_putendl("is sort");
	ft_putnbr(stack_is_sort(st));
	ft_putchar('\n');
	return (0);
}
