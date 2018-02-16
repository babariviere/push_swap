/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:30:51 by briviere          #+#    #+#             */
/*   Updated: 2018/02/16 14:20:03 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	is_number(const char *s)
{
	(void)s;
	return (1);
}

t_stack		*stack_from_args(int ac, char **av)
{
	t_stack	*res;
	int		tmp;

	if ((res = stack_create(1024)) == 0)
		return (0);
	// TODO: split av
	while (--ac > 0)
	{
		if (!is_number(av[ac]))
		{
			stack_delete(&res);
			return (0);
		}
		tmp = ft_atoi(av[ac]);
		stack_push(res, tmp);
	}
	return (res);
}
