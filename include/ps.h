/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:13:46 by briviere          #+#    #+#             */
/*   Updated: 2018/02/16 13:46:02 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "libft.h"

typedef struct	s_stack {
	int		*data;
	size_t	len;
}				t_stack;

t_stack		*stack_create(size_t size);
void		stack_delete(t_stack **stack);
void		stack_push(t_stack *stack, int nb);
int			stack_pop(t_stack *stack);
void		stack_swap(t_stack *stack);
void		stack_rotate(t_stack *stack);
void		stack_rrotate(t_stack *stack);
int			stack_is_sort(const t_stack *stack);

t_stack		*stack_from_args(int ac, char **av);

#endif
