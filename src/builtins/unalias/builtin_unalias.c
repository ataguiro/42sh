/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unalias.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:11:48 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/20 17:39:11 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "environment.h"
#include "libft.h"

static int	unset_argument_alias(t_variable **lst_alias, char **av)
{
	int		i;
	int		error;

	i = 0;
	if (!av[i])
	{
		ft_putendl_fd("unalias: not enough arguments.", 2);
		return (1);
	}
	error = 0;
	while (av[i])
	{
		if (!sh_unsetenv(lst_alias, av[i]))
		{
			ft_putstr_fd("unalias: no such hash table element : ", 2);
			ft_putendl_fd(av[i], 2);
			error = 1;
		}
		++i;
	}
	return (error);
}

static int	is_all_option(char **av, int *option)
{
	int		i;
	int		j;

	i = 0;
	while (av[++i] && av[i][0] == '-' && (av[i][1] || !(++i)))
	{
		if (ft_strequ(av[i], "--"))
		{
			if (!av[++i] && !*option)
				ft_putendl_fd("unalias : not enough arguments.", 2);
			return (!av[i] && !*option ? -1 : i);
		}
		j = 0;
		while (av[i][++j])
			if (av[i][j] != 'a')
			{
				ft_putstr_fd("42sh: bad option : -", 2);
				ft_putchar_fd(av[i][j], 2);
				ft_putchar_fd('\n', 2);
				return (-1);
			}
			else
				*option = 1;
	}
	return (i);
}

int			builtin_unalias(t_shell *sh, int ac, char **av)
{
	int		i;
	int		option;
	int		error;

	option = 0;
	if ((i = is_all_option(av, &option)) == -1)
		return (1);
	else
	{
		if (option)
		{
			if (!av[i] && !(error = 0))
				clear_env_list(&sh->lst_alias);
			else if ((error = 1))
				ft_putendl_fd("unalias : -a: too many arguments.", 2);
		}
		else
			error = unset_argument_alias(&sh->lst_alias, av + i);
	}
	(void)ac;
	return (error);
}
