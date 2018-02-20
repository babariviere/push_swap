/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_hlp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:13:46 by briviere          #+#    #+#             */
/*   Updated: 2018/02/20 09:37:35 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int			instr_change_a(t_instr instr)
{
	if (instr == INSTR_RB || instr == INSTR_SB || instr == INSTR_RRB)
		return (0);
	return (1);
}

int			instr_change_b(t_instr instr)
{
	if (instr == INSTR_RA || instr == INSTR_SA || instr == INSTR_RRA)
		return (0);
	return (1);
}

int			instr_conflict(t_instr ins1, t_instr ins2)
{
	return ((instr_change_a(ins1) && instr_change_a(ins2)) ||
			(instr_change_b(ins1) && instr_change_b(ins2)));
}

int			instr_is_opposite(t_instr ins1, t_instr ins2)
{
	if (ins1 == INSTR_SA && ins2 == INSTR_SA)
		return (1);
	if (ins1 == INSTR_SB && ins2 == INSTR_SB)
		return (1);
	if (ins1 == INSTR_SS && ins2 == INSTR_SS)
		return (1);
	if (ins1 == INSTR_PA && ins2 == INSTR_PB)
		return (1);
	if (ins1 == INSTR_PB && ins2 == INSTR_PA)
		return (1);
	if (ins1 == INSTR_RA && ins2 == INSTR_RRA)
		return (1);
	if (ins1 == INSTR_RRA && ins2 == INSTR_RA)
		return (1);
	if (ins1 == INSTR_RB && ins2 == INSTR_RRB)
		return (1);
	if (ins1 == INSTR_RRB && ins2 == INSTR_RB)
		return (1);
	if (ins1 == INSTR_RR && ins2 == INSTR_RRR)
		return (1);
	if (ins1 == INSTR_RRR && ins2 == INSTR_RR)
		return (1);
	return (0);
}
