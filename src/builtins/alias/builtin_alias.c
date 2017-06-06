/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:43:43 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/20 17:46:16 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "environment.h"
#include "ft_42sh.h"
#include "builtins.h"
#include "tools.h"

static int	assign_alias(t_variable **lst_alias, char *av, char *value)
{
	char	*key;

	if (!(key = tl_strndup(av, (size_t)(value - av))))
		return (ERROR);
	sh_setenv(lst_alias, key, value + 1);
	ft_strdel(&key);
	return (GOOD);
}

static int	search_alias(t_variable *lst_alias, char *av)
{
	t_variable	*ptr;
	char		*key;
	int			j;

	ptr = lst_alias;
	while (ptr)
	{
		if ((key = var_getkey(ptr->variable)))
		{
			if (ft_strequ(key, av))
			{
				j = 0;
				while (ptr->variable[j] && ptr->variable[j] != '=')
					ft_putchar(ptr->variable[j++]);
				ft_putstr("='");
				ft_putstr(ptr->variable + j + 1);
				ft_putstr("'\n");
				ft_strdel(&key);
				return (GOOD);
			}
			ft_strdel(&key);
		}
		ptr = ptr->next;
	}
	return (ERROR);
}

static int	is_option(char **av)
{
	int		i;

	i = 1;
	while (av[i] && av[i][0] == '-')
	{
		if (av[i][1] == 0 || ft_strequ(av[i], "--"))
			return (++i);
		else
		{
			ft_putstr_fd("42sh: bad option: -", 2);
			ft_putchar_fd(av[i][1], 2);
			ft_putchar_fd('\n', 2);
			return (-1);
		}
		++i;
	}
	return (i);
}

int			builtin_alias(t_shell *sh, int ac, char **av)
{
	int		i;
	int		error;
	char	*value;

	error = 0;
	if ((i = is_option(av)) == -1 && ac)
		return (1);
	if (!av[i])
		print_alias(sh->lst_alias);
	else
		while (av[i])
		{
			if ((value = ft_strchr(av[i], '=')))
			{
				if (!assign_alias(&sh->lst_alias, av[i], value))
					error = 1;
			}
			else
			{
				if (!search_alias(sh->lst_alias, av[i]))
					error = 1;
			}
			i++;
		}
	return (error);
}
