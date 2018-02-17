/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_hlp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:55:50 by briviere          #+#    #+#             */
/*   Updated: 2018/02/17 18:24:57 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

inline int	stack_cmp_top(const t_stack *st)
{
	if (st->len <= 1)
		return (0);
	return (ST_TOP(st) - ST_TOPN(st));
}

inline int	stack_cmp_bot(const t_stack *st)
{
	if (st->len <= 1)
		return (0);
	return (ST_BOT(st) - ST_BOTN(st));
}

inline int	stack_cmp_bot_top(const t_stack *st)
{
	if (st->len <= 1)
		return (0);
	return (ST_BOT(st) - ST_TOP(st));
}

void		print_stack(const t_stack *st, char name)
{
	size_t		idx;

	ft_putchar(name);
	ft_putstr(": ");
	idx = 0;
	while (idx < st->len)
	{
		ft_putnbr(st->data[idx++]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
}
