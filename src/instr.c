/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:53:13 by briviere          #+#    #+#             */
/*   Updated: 2018/02/16 14:08:11 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
static t_instr	into_instr(char *buf)
{
	if (ft_strequ(buf, "sa"))
		return(INSTR_SA);
	if (ft_strequ(buf, "sb"))
		return(INSTR_SB);
	if (ft_strequ(buf, "ss"))
		return(INSTR_SS);
	if (ft_strequ(buf, "pa"))
		return(INSTR_PA);
	if (ft_strequ(buf, "pb"))
		return(INSTR_PB);
	if (ft_strequ(buf, "ra"))
		return(INSTR_RA);
	if (ft_strequ(buf, "rb"))
		return(INSTR_RB);
	if (ft_strequ(buf, "rr"))
		return(INSTR_RR);
	if (ft_strequ(buf, "rra"))
		return(INSTR_RRA);
	if (ft_strequ(buf, "rrb"))
		return(INSTR_RRB);
	if (ft_strequ(buf, "rrr"))
		return(INSTR_RRR);
	return (INSTR_INV);
}

t_instr			read_instr(void)
{
	char	*buf;
	t_instr	instr;
	int		res;

	if ((res = ft_gnl(0, &buf)) <= 0)
		return (res);
	instr = into_instr(buf);
	free(buf);
	return (instr);
}

static void		apply_instr_push(t_stack *a, t_stack *b, t_instr instr)
{
	if (instr == INSTR_PA)
	{
		if (b->len == 0)
			return ;
		stack_push(a, stack_pop(b));
	}
	if (instr == INSTR_PB)
	{
		if (a->len == 0)
			return ;
		stack_push(b, stack_pop(a));
	}
}

void			apply_instr(t_stack *a, t_stack *b, t_instr instr)
{
	if (instr == INSTR_SA || instr == INSTR_SS)
		stack_swap(a);
	if (instr == INSTR_SB || instr == INSTR_SS)
		stack_swap(b);
	apply_instr_push(a, b, instr);
	if (instr == INSTR_RA || instr == INSTR_RR)
		stack_rotate(a);
	if (instr == INSTR_RB || instr == INSTR_RR)
		stack_rotate(b);
	if (instr == INSTR_RRA || instr == INSTR_RRR)
		stack_rrotate(a);
	if (instr == INSTR_RRB || instr == INSTR_RRR)
		stack_rrotate(b);
}
