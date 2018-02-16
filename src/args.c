/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:30:51 by briviere          #+#    #+#             */
/*   Updated: 2018/02/16 14:40:55 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	is_number(const char *s)
{
	size_t		idx;

	if (s == 0 || s[0] == 0)
		return (0);
	if (s[0] != '-' && !ft_isdigit(s[0]))
		return (0);
	idx = 1;
	while (s[idx])
	{
		if (!ft_isdigit(s[idx]))
			return (0);
		idx++;
	}
	return (1);
}

t_stack		*stack_from_args(int ac, char **av)
{
	t_stack	*res;
	char	**nbs;
	int		tmp;
	size_t	idx;

	if ((res = stack_create(1024)) == 0)
		return (0);
	while (--ac > 0)
	{
		if ((nbs = ft_strsplit(av[ac], ' ')) == 0)
			return (0);
		idx = 0;
		while (nbs[idx])
			idx++;
		while (idx-- > 0)
		{
			if (!is_number(nbs[idx]))
				return (0);
			tmp = ft_atoi(nbs[idx]);
			stack_push(res, tmp);
			free(nbs[idx]);
		}
		ft_memdel((void **)&nbs);
	}
	return (res);
}
