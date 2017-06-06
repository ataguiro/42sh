/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <cjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:47:48 by cjacquem          #+#    #+#             */
/*   Updated: 2016/12/06 15:35:01 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "environment.h"
#include "libft.h"

static int	is_format_valid(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (ERROR);
		i++;
	}
	return (GOOD);
}

static int	check_validity_av(char *argv)
{
	if (!ft_isalpha(*argv) && *argv != '_')
	{
		ft_putendl_fd("setenv: Variable name must begin with a letter.", 2);
		return (ERROR);
	}
	else if (!is_format_valid(argv))
	{
		ft_putstr_fd("setenv: ", 2);
		ft_putendl_fd("Variable name must contain alphanumeric characters.", 2);
		return (ERROR);
	}
	return (GOOD);
}

int			builtin_setenv(t_shell *sh, int ac, char **av)
{
	if (ac == 1)
		sh_print_env(sh->lst_env);
	else if (ac == 2 || ac == 3)
	{
		if (!check_validity_av(av[1]))
			return (1);
		sh_setenv(&sh->lst_env, av[1], av[2] ? av[2] : "");
	}
	else if (ac > 3)
	{
		ft_putendl_fd("setenv: Too many arguments.", 2);
		return (1);
	}
	return (0);
}
