/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_hlp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:55:50 by briviere          #+#    #+#             */
/*   Updated: 2018/02/16 17:01:44 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

inline int	stack_cmp_top(t_stack *st)
{
	if (st->len <= 1)
		return (0);
	return (st->data[st->len - 1] - st->data[st->len - 2]);
}

inline int	stack_cmp_bot(t_stack *st)
{
	if (st->len <= 1)
		return (0);
	return (st->data[0] - st->data[1]);
}

inline int	stack_cmp_bot_top(t_stack *st)
{
	if (st->len <= 1)
		return (0);
	return (st->data[0] - st->data[st->len - 1]);
}
