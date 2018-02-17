/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fnd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 16:49:22 by briviere          #+#    #+#             */
/*   Updated: 2018/02/17 16:53:39 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		stack_find_unsorted_top(const t_stack *st)
{
	int		idx;

	idx = st->len;
	while (idx-- > 1)
	{
		if (st->data[idx - 1] < st->data[idx])
			return (idx);
	}
	return (-1);
}
