/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:18:56 by briviere          #+#    #+#             */
/*   Updated: 2018/02/16 16:25:30 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_stack		*stack_create(size_t size)
{
	t_stack	*res;

	if ((res = ft_memalloc(sizeof(t_stack))) == 0)
		return (0);
	if ((res->data = ft_memalloc(sizeof(int) * size)) == 0)
		return (0);
	res->len = 0;
	res->alloc = size;
	return (res);
}

void		stack_delete(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp == 0)
		return ;
	if (tmp->data)
		free(tmp->data);
	ft_memdel((void **)stack);
}
