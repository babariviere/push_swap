/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:13:46 by briviere          #+#    #+#             */
/*   Updated: 2018/02/20 09:37:58 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "libft.h"

# define ST_TOP(st) (st->data[st->len - 1])
# define ST_TOPN(st) (st->data[st->len - 2])
# define ST_BOT(st) (st->data[0])
# define ST_BOTN(st) (st->data[1])

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

typedef struct	s_stack_hld {
	t_stack		*a;
	t_stack		*b;
	t_stack		*instr;
}				t_stack_hld;

typedef struct	s_opts {
	int		verbose;
}				t_opts;

void			write_instr(t_instr instr);
t_instr			read_instr(void);
t_instr			instr_try_optimize(t_instr ins1, t_instr ins2);
void			apply_instr(t_stack *a, t_stack *b, t_instr instr);
void			apply_instr_and_save(t_stack_hld *hld, t_instr instr);
int				instr_change_a(t_instr instr);
int				instr_change_b(t_instr instr);
int				instr_conflict(t_instr ins1, t_instr ins2);
int				instr_is_opposite(t_instr ins1, t_instr ins2);

t_stack			*stack_create(size_t size);
void			stack_delete(t_stack **stack);
void			stack_push(t_stack *stack, int nb);
int				stack_pop(t_stack *stack);
void			stack_swap(t_stack *stack);
void			stack_rotate(t_stack *stack);
void			stack_rrotate(t_stack *stack);
int				stack_is_sort(const t_stack *stack);
int				stack_is_rsort(const t_stack *stack);
int				stack_has_dup(const t_stack *stack);

int				stack_cmp_top(const t_stack *st);
int				stack_cmp_bot(const t_stack *st);
int				stack_cmp_bot_top(const t_stack *st);
void			print_stack(const t_stack *st, char name);

t_stack			*stack_from_args(int ac, char **av, t_opts *opts);

void			sort_stack(t_stack_hld *hld);

#endif
