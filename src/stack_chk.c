/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_chk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:44:04 by briviere          #+#    #+#             */
/*   Updated: 2018/02/16 14:34:04 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		stack_is_sort(const t_stack *stack)
{
	size_t		idx;

	idx = stack->len;
	if (stack->len <= 1)
		return (1);
	while (--idx > 0)
	{
		if (stack->data[idx - 1] < stack->data[idx])
			return (0);
	}
	return (1);
}

int		stack_has_dup(const t_stack *stack)
{
	size_t		idx;
	size_t		sidx;

	idx = 0;
	if (stack->len <= 1)
		return (1);
	while (idx < (stack->len - 1))
	{
		sidx = idx + 1;
		while (sidx < stack->len)
		{
			if (stack->data[idx] == stack->data[sidx])
				return (1);
			sidx++;
		}
		idx++;
	}
	return (0);
}
