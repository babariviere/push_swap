/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:14:39 by briviere          #+#    #+#             */
/*   Updated: 2018/02/16 15:39:18 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		calc_average(const t_stack *st)
{
	size_t	idx;
	int		total;

	total = 0;
	idx = 0;
	while (idx < st->len)
		total += st->data[idx++];
	return (total / st->len);
}

int		get_lower(const t_stack *st)
{
	size_t	idx;
	int		lower;

	idx = 1;
	lower = st->data[0];
	while (idx < st->len)
	{
		if (st->data[idx] < lower)
			lower = st->data[idx];
		idx++;
	}
	return (lower);
}

int		get_highest(const t_stack *st)
{
	size_t	idx;
	int		higher;

	idx = 1;
	higher = st->data[0];
	while (idx < st->len)
	{
		if (st->data[idx] > higher)
			higher = st->data[idx];
		idx++;
	}
	return (higher);
}
