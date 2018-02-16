/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:30:51 by briviere          #+#    #+#             */
/*   Updated: 2018/02/16 13:36:59 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_stack		*stack_from_args(int ac, char **av)
{
	t_stack	*res;
	int		tmp;

	if ((res = stack_create(ac - 1)) == 0)
		return (0);
	while (--ac > 0)
	{
		tmp = ft_atoi(av[ac]);
		stack_push(res, tmp);
	}
	return (res);
}
