/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:53:13 by briviere          #+#    #+#             */
/*   Updated: 2018/02/17 12:59:48 by briviere         ###   ########.fr       */
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

void			write_instr(t_instr instr)
{
	if (instr == INSTR_SA)
		ft_putstr("sa");
	else if (instr == INSTR_SB)
		ft_putstr("sb");
	else if (instr == INSTR_SS)
		ft_putstr("ss");
	else if (instr == INSTR_PA)
		ft_putstr("pa");
	else if (instr == INSTR_PB)
		ft_putstr("pb");
	else if (instr == INSTR_RA)
		ft_putstr("ra");
	else if (instr == INSTR_RB)
		ft_putstr("rb");
	else if (instr == INSTR_RR)
		ft_putstr("rr");
	else if (instr == INSTR_RRA)
		ft_putstr("rra");
	else if (instr == INSTR_RRB)
		ft_putstr("rrb");
	else if (instr == INSTR_RRR)
		ft_putstr("rrr");
}

t_instr			instr_try_optimize(t_instr ins1, t_instr ins2)
{
	if ((ins1 == INSTR_SA && ins2 == INSTR_SB) ||
			(ins1 == INSTR_SB && ins2 == INSTR_SA))
		return (INSTR_SS);
	if ((ins1 == INSTR_RA && ins2 == INSTR_RB) ||
			(ins1 == INSTR_RB && ins2 == INSTR_RA))
		return (INSTR_RR);
	if ((ins1 == INSTR_RRA && ins2 == INSTR_RRB) ||
			(ins1 == INSTR_RRB && ins2 == INSTR_RRA))
		return (INSTR_RRR);
	return (INSTR_NONE);
}
