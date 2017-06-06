/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:26:25 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/15 13:00:57 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"
#include "tools.h"
#include "builtins.h"

static int	is_format_correct(char *str)
{
	int		i;
	int		error;

	i = 1;
	error = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) || str[i] == '=')
		{
			if (str[i] != '=')
				error = 1;
			break ;
		}
		i++;
	}
	if (!ft_isalpha(*str) || error)
	{
		ft_putstr_fd("42sh: export: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (ERROR);
	}
	return (GOOD);
}

static void	set_local_var(t_shell *sh, char *str)
{
	char	*key;
	char	*value;

	value = NULL;
	if (!(value = ft_strchr(str, '=')))
		sh_setenv(&sh->lst_localvar, str, "");
	else
	{
		if (!(key = tl_strndup(str, (size_t)(value - str))))
			return ;
		sh_setenv(&sh->lst_localvar, key, value + 1);
		ft_strdel(&key);
	}
}

int			builtin_export(t_shell *sh, int ac, char **av)
{
	int		i;
	_Bool	error;

	error = 0;
	if (ac == 1)
		print_export(sh->lst_env, sh->lst_localvar);
	else
	{
		i = 1;
		while (av[i])
		{
			if (is_format_correct(av[i]))
				set_local_var(sh, av[i]);
			else
				error = 1;
			i++;
		}
	}
	return (error);
}
