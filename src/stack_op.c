/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:23:31 by briviere          #+#    #+#             */
/*   Updated: 2018/02/17 18:26:16 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	stack_push(t_stack *stack, int nb)
{
	if ((stack->len + 1) >= stack->alloc)
	{
		stack->data = ft_realloc(stack->data, sizeof(int) * stack->alloc,
				sizeof(int) * (stack->alloc * 2));
		stack->alloc *= 2;
	}
	stack->data[stack->len++] = nb;
}

int		stack_pop(t_stack *stack)
{
	return (stack->data[--stack->len]);
}

void	stack_swap(t_stack *stack)
{
	int		tmp;

	if (stack->len <= 1)
		return ;
	tmp = ST_TOPN(stack);
	ST_TOPN(stack) = ST_TOP(stack);
	ST_TOP(stack) = tmp;
}

void	stack_rotate(t_stack *stack)
{
	size_t		idx;
	int			first;

	if (stack->len <= 1)
		return ;
	first = stack->data[stack->len - 1];
	idx = stack->len - 1;
	while (idx-- > 0)
		stack->data[idx + 1] = stack->data[idx];
	stack->data[0] = first;
}

void	stack_rrotate(t_stack *stack)
{
	size_t		idx;
	int			last;

	if (stack->len <= 1)
		return ;
	last = stack->data[0];
	idx = 1;
	while (idx < stack->len)
	{
		stack->data[idx - 1] = stack->data[idx];
		idx++;
	}
	stack->data[stack->len - 1] = last;
}
