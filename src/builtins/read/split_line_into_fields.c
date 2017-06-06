/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line_into_fields.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:30:02 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/12 19:11:55 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include "ft_42sh.h"
#include "environment.h"

#define DEFAULT_IFS " \t\n\0"

static int	is_ifs_char(char *ifs, char c)
{
	int		j;

	j = 0;
	while (ifs[j])
	{
		if (ifs[j] == c)
			return (GOOD);
		j++;
	}
	return (ERROR);
}

static int	set_read_arguments(t_shell *sh, char **av, char *line, char *ifs)
{
	char	*value;
	int		tmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	tmp = 0;
	while (line[++i] && av[j + 1])
		if (is_ifs_char(ifs, line[i]))
		{
			if (i != tmp && (value = tl_strndup(line + tmp, i - tmp)))
			{
				sh_setenv(&sh->lst_localvar, av[j++], value);
				ft_strdel(&value);
			}
			while (is_ifs_char(ifs, line[i]))
				i++;
			tmp = i;
		}
	if (!(value = ft_strdup(line + tmp)))
		return (ERROR);
	sh_setenv(&sh->lst_localvar, av[j++], value);
	ft_strdel(&value);
	return (GOOD);
}

static void	shift_string(char *str, char *ifs)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] && is_ifs_char(ifs, str[j]))
		j++;
	while (str[j])
	{
		str[i] = str[j];
		i++;
		j++;
	}
	ft_strclr(str + i);
}

static void	epur_tab(char *value, char *ifs)
{
	int		j;

	j = 0;
	while (value && value[j])
	{
		if (is_ifs_char(ifs, value[j]))
		{
			value[j] = ' ';
			shift_string(value + j + 1, ifs);
		}
		j++;
	}
}

void		split_line_into_fields(t_shell *sh, char **av, char *line)
{
	char	*ifs;
	int		i;
	char	*value;

	if (!av)
		return ;
	if (!(ifs = sh_getenv(sh->lst_localvar, "IFS")))
		ifs = sh_getenv(sh->lst_env, "IFS");
	if (!*av)
	{
		sh_setenv(&sh->lst_localvar, "REPLY", line);
		value = sh_getenv(sh->lst_localvar, "REPLY");
		epur_tab(value, ifs ? ifs : DEFAULT_IFS);
	}
	else if (!av[1])
		sh_setenv(&sh->lst_localvar, *av, line);
	else
		set_read_arguments(sh, av, line, ifs ? ifs : DEFAULT_IFS);
	i = -1;
	while (av && av[++i])
	{
		value = sh_getenv(sh->lst_localvar, av[i]);
		epur_tab(value, ifs ? ifs : DEFAULT_IFS);
	}
}
