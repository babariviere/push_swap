/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:13:46 by briviere          #+#    #+#             */
/*   Updated: 2018/02/16 14:32:37 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "libft.h"

typedef enum	e_instr {
	INSTR_INV = -1,
	INSTR_NONE = 0,
	INSTR_SA,
	INSTR_SB,
	INSTR_SS,
	INSTR_PA,
	INSTR_PB,
	INSTR_RA,
	INSTR_RB,
	INSTR_RR,
	INSTR_RRA,
	INSTR_RRB,
	INSTR_RRR,
}				t_instr;

typedef struct	s_stack {
	int		*data;
	size_t	alloc;
	size_t	len;
}				t_stack;

t_instr			read_instr(void);
void			apply_instr(t_stack *a, t_stack *b, t_instr instr);

t_stack		*stack_create(size_t size);
void		stack_delete(t_stack **stack);
void		stack_push(t_stack *stack, int nb);
int			stack_pop(t_stack *stack);
void		stack_swap(t_stack *stack);
void		stack_rotate(t_stack *stack);
void		stack_rrotate(t_stack *stack);
int			stack_is_sort(const t_stack *stack);
int			stack_has_dup(const t_stack *stack);

t_stack		*stack_from_args(int ac, char **av);

#endif
