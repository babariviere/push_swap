/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_chk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:44:04 by briviere          #+#    #+#             */
/*   Updated: 2018/02/16 13:46:21 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		stack_is_sort(const t_stack *stack)
{
	size_t		idx;

	idx = stack->len;
	while (--idx > 0)
	{
		if (stack->data[idx - 1] < stack->data[idx])
			return (0);
	}
	return (1);
}
