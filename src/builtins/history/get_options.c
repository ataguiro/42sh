/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:09:24 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/19 14:29:19 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"
#include "builtin_history.h"
#include "tools.h"

static int	check_offset(t_hist_option *tools, char *str)
{
	if (tl_isstrdigit(str))
	{
		tools->offset = ft_atoi(str);
		tools->option |= OPTION_D;
	}
	else
	{
		ft_putstr_fd("42sh: history: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": history position out of range\n", 2);
		return (ERROR);
	}
	return (GOOD);
}

static int	get_d_option(t_hist_option *tools, char **av, int *i, int *j)
{
	int		ret;

	if (av[*i][++(*j)])
	{
		ret = check_offset(tools, &av[*i][*j]);
		*j = 0;
		(*i)++;
	}
	else if (av[++(*i)])
	{
		*j = 0;
		ret = check_offset(tools, av[*i]);
		(*i)++;
	}
	else
	{
		ft_putstr_fd("42sh: history: -d: option requires an argument\n", 2);
		return (ERROR);
	}
	return (ret);
}

static int	is_option(t_hist_option *tools, char **av, int *i, int *j)
{
	if (av[*i][*j] == 'c')
		tools->option |= OPTION_C;
	else if (av[*i][*j] == 'd')
		return (get_d_option(tools, av, i, j));
	else if (av[*i][*j] == 'r')
		tools->option |= OPTION_R;
	else if (av[*i][*j] == 'p')
		tools->option |= OPTION_P;
	else if (av[*i][*j] == 's')
		tools->option |= OPTION_S;
	else if (av[*i][*j] == 'w')
		tools->option |= OPTION_W;
	else if (av[*i][*j] == 'a')
		tools->option |= OPTION_A;
	else
	{
		ft_putstr_fd("42sh: history: -", 2);
		ft_putchar_fd(av[*i][*j], 2);
		ft_putstr_fd(": invalid option\n", 2);
		return (ERROR);
	}
	return (GOOD);
}

static int	check_awrn(t_hist_option tools)
{
	int		i;

	i = 0;
	if (tools.option & OPTION_A)
		i++;
	if (tools.option & OPTION_W)
		i++;
	if (tools.option & OPTION_R)
		i++;
	if (i > 1)
	{
		ft_putstr_fd("42sh: history: cannot use more than one of -arw\n", 2);
		return (ERROR);
	}
	return (GOOD);
}

int			history_get_options(t_hist_option *tools, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i] && av[i][0] == '-')
	{
		if (ft_strequ(av[i], "--"))
			return (++i);
		j = 1;
		while (av[i] && av[i][j])
		{
			if (is_option(tools, av, &i, &j) == 0)
				return (-1);
			if (av[i] && av[i][j])
				j++;
		}
		if (av[i])
			i++;
	}
	return ((j = check_awrn(*tools)) == GOOD ? i : j);
}
