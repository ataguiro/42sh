/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:05:40 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/15 14:38:30 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_read.h"
#include "libft.h"
#include "ft_42sh.h"

static int		option_without_arg(t_read *tools, char c)
{
	if (c == 'e')
		tools->option |= OPTION_E;
	else if (c == 'r')
		tools->option |= OPTION_R;
	else if (c == 's')
		tools->option |= OPTION_S;
	else
	{
		ft_putstr_fd("42sh: bad option: -", 2);
		ft_putchar_fd(c, 2);
		ft_putchar_fd('\n', 2);
		return (-1);
	}
	return (0);
}

static int		is_option(t_read *tools, char **av, int *i, int *j)
{
	const char	options[] = "dnptu";
	int			x;
	static int	(*p[5])(t_read *, char **, int *, int *);

	p[0] = read_option_d;
	p[1] = read_option_n;
	p[2] = read_option_p;
	p[3] = read_option_t;
	p[4] = read_option_u;
	x = 0;
	while (options[x])
	{
		if (options[x] == av[*i][*j])
		{
			(*j)++;
			return ((p[x])(tools, av, i, j) ? 1 : -1);
		}
		x++;
	}
	return (option_without_arg(tools, av[*i][*j]));
}

int				read_get_options(char **av, t_read *tools)
{
	int			i;
	int			j;
	int			ret;

	i = 1;
	while (av[i] && *(av[i]) == '-')
	{
		if (ft_strequ(av[i], "--"))
			return (++i);
		j = 1;
		while (av[i] && av[i][j])
		{
			if ((ret = is_option(tools, av, &i, &j)) == -1)
				return (-1);
			if (ret == 1)
				break ;
			if (av[i] && av[i][j])
				j++;
		}
		if (av[i])
			i++;
	}
	return (i);
}
