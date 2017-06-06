/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_a_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 21:39:38 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/03 14:15:36 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include "input.h"
#include "ft_42sh.h"

#define ALL_BUILTINS _BUILTIN1 _BUILTIN2 _BINARY_BUILTIN

extern t_shell	g_sh;

static int	search_through_tab(char **tab, char *command)
{
	int		i;
	int		len;
	int		found;

	i = 0;
	len = ft_strlen(command);
	found = 0;
	while (tab && tab[i])
	{
		if (ft_strnequ(command, tab[i], len) && (found = 1))
		{
			tl_lstadd_sortalpha(get_list_completion(), \
				ft_lstnew(tab[i], ft_strlen(tab[i]) + 1));
		}
		i++;
	}
	return (found);
}

int			look_for_a_command(char *command)
{
	char	**tab;
	char	*path;
	int		i;

	if (ft_strchr(command, '/'))
		return (look_for_a_file(command));
	tab = ft_strsplit(ALL_BUILTINS, ' ');
	search_through_tab(tab, command);
	tl_freedoubletab(tab);
	tab = NULL;
	if (!(path = sh_getenv(g_sh.lst_env, "PATH")))
		return (1);
	tab = ft_strsplit(path, ':');
	i = 0;
	while (tab && tab[i])
	{
		search_through_dir(tab[i], command);
		i++;
	}
	tl_freedoubletab(tab);
	return (0);
}
