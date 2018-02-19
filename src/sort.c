/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:17:10 by briviere          #+#    #+#             */
/*   Updated: 2018/02/19 17:03:09 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	find_median(int *data, int idx, int len)
{
	int		low;
	int		high;
	int		median;
	int		tmp_len;

	low = data[idx];
	high = data[idx];
	median = idx;
	tmp_len = len;
	while (len--)
	{
		if (data[idx] > high)
			high = data[idx];
		else if (data[idx] < low)
			low = data[idx];
		idx--;
	}
	idx = median;
	median = high;
	while (tmp_len--)
	{
		if (low < data[idx] && data[idx] < high)
			median = data[idx];
		idx--;
	}
	return (median);
}

static int	split_list(t_stack_hld *hld, int len)
{
	int		median;
	int		pushed;

	median = find_median(hld->a->data, hld->a->len - 1, len);
	pushed = 0;
	while (len--)
	{
		if (ST_TOP(hld->a) < median)
		{
			apply_instr_and_save(hld, INSTR_PB);
			pushed++;
		}
		else
			apply_instr_and_save(hld, INSTR_RA);
	}
	return (pushed);
}

static void	quick_sort(t_stack_hld *hld, int len)
{
	int		pushed;
	int		count;

	if (len <= 1)
		return ;
	pushed = split_list(hld, len);
	count = len - pushed;
	while (count-- > 0)
		apply_instr_and_save(hld, INSTR_RRA);
	count = pushed;
	while (count-- > 0)
		apply_instr_and_save(hld, INSTR_PA);
	quick_sort(hld, pushed);
	count = pushed;
	while (count-- > 0)
		apply_instr_and_save(hld, INSTR_RA);
	quick_sort(hld, len - pushed);
	count = pushed;
	while (count-- > 0)
		apply_instr_and_save(hld, INSTR_RRA);
}

void		sort_stack(t_stack_hld *hld)
{
	if (stack_is_sort(hld->a) && hld->b->len == 0)
		return ;
	quick_sort(hld, hld->a->len);
}
