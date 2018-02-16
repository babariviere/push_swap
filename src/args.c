/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:30:51 by briviere          #+#    #+#             */
/*   Updated: 2018/02/16 14:57:03 by briviere         ###   ########.fr       */
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

static int	parse_arg(char *arg, t_stack *res, t_opts *opts)
{
	char	**nbs;
	int		tmp;
	size_t	idx;

	if (ft_strequ(arg, "-v"))
		return ((opts == 0 ? 0 : (opts->verbose = 1)));
	if ((nbs = ft_strsplit(arg, ' ')) == 0)
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
	return (1);
}

t_stack		*stack_from_args(int ac, char **av, t_opts *opts)
{
	t_stack	*res;

	if ((res = stack_create(1024)) == 0)
		return (0);
	while (--ac > 0)
	{
		if (parse_arg(av[ac], res, opts) == 0)
			return (0);
	}
	return (res);
}
