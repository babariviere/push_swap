/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_hlp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:13:46 by briviere          #+#    #+#             */
/*   Updated: 2018/02/17 18:20:51 by briviere         ###   ########.fr       */
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
