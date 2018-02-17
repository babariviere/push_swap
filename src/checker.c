/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:12:39 by briviere          #+#    #+#             */
/*   Updated: 2018/02/17 13:16:49 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	exec_instr(t_stack *a, t_stack *b, t_stack *instr,
		t_opts opts)
{
	size_t		idx;

	idx = 0;
	if (opts.verbose)
		print_stack(a, 'a');
	while (idx < instr->len)
	{	
		apply_instr(a, b, instr->data[idx++]);
		if (opts.verbose)
		{
			print_stack(a, 'a');
			print_stack(b, 'b');
		}
	}
}

static void	exec_checker(t_stack *a, t_stack *b, t_opts opts)
{
	t_instr		tmp;
	t_stack		*instr;

	instr = stack_create(1024);
	while ((tmp = read_instr()) > 0)
		stack_push(instr, tmp);
	if (tmp == INSTR_INV)
	{
		stack_delete(&instr);
		return (ft_putendl_fd("Error", 2));
	}
	exec_instr(a, b, instr, opts);
	if (!stack_is_sort(a) || b->len > 0)
		ft_putendl("KO");
	else
		ft_putendl("OK");
	stack_delete(&instr);
}

int			main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_opts		opts;

	a = 0;
	b = 0;
	opts = (t_opts){0};
	if ((a = stack_from_args(ac, av, &opts)) == 0)
		ft_putendl_fd("Error", 2);
	else if ((b = stack_create(a->len)) == 0)
		ft_putendl_fd("Error", 2);
	else if (stack_has_dup(a))
		ft_putendl_fd("Error", 2);
	else
		exec_checker(a, b, opts);
	stack_delete(&a);
	stack_delete(&b);
	return (0);
}
