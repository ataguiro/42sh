/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <cjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:49:16 by cjacquem          #+#    #+#             */
/*   Updated: 2017/01/24 11:34:09 by cjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include "ft_42sh.h"
#include "environment.h"
#include "builtins.h"
#include "libft.h"
#include "tools.h"

/*
**			This function change the working directory of the current shell
**			execution environment.
**			cd -P -> Do not follow symbolic links
**				(ex: PWD=/private/tmp)
**			cd -L -> Follow symbolic links  >>>>> DEFAULT
**				(ex: PWD=/tmp)
*/

static void	append_one_dir(char **path, char *wanted)
{
	char	*tmp;

	tmp = (*path)[1] ? ft_strjoin(*path, "/") : ft_strdup(*path);
	*path ? ft_strdel(path) : 0;
	*path = ft_strjoin(tmp, wanted);
	tmp ? ft_strdel(&tmp) : 0;
}

static int	gear(char **path, char **tmp)
{
	char	*p;
	int		i;

	i = 0;
	while (tmp[i])
	{
		if (ft_strequ(tmp[i], "."))
			;
		else if (ft_strequ(tmp[i], ".."))
		{
			if ((p = ft_strrchr(*path, '/')))
				while (*p)
				{
					if (p == *path)
						++p;
					*p = '\0';
					++p;
				}
		}
		else
			append_one_dir(path, tmp[i]);
		++i;
	}
	return (GOOD);
}

static char	*build_path(t_variable *lst_env, char *wanted)
{
	char	*path;
	char	**tmp;

	if (wanted[0] != '/')
	{
		if ((path = sh_getenv(lst_env, "PWD")))
		{
			if (!(path = ft_strdup(path)))
				return (NULL);
		}
		else if (!(path = getcwd(NULL, _POSIX_PATH_MAX)))
			return (NULL);
		if (!(tmp = ft_strsplit(wanted, '/')))
			return (NULL);
		if (tl_arrlen(tmp) == 0 && ft_strequ(wanted, "/"))
			return (ft_strdup(wanted));
		gear(&path, tmp);
		tl_freedoubletab(tmp);
	}
	else
		path = ft_strdup(wanted);
	return (path);
}

int			builtin_cd(t_shell *sh, int ac, char **av)
{
	char	*path;
	_Bool	follow_sl;
	int		i;

	i = 1;
	follow_sl = get_options(av, &i);
	if (!av[i])
	{
		if (!(path = ft_strdup(getpwuid(getuid())->pw_dir)))
			return (cd_error(1, NULL));
	}
	else if (ac - i == 1)
	{
		if (ft_strequ(av[i], "-"))
		{
			if (!(path = ft_strdup(sh_getenv(sh->lst_env, "OLDPWD"))))
				return (cd_error(2, NULL));
		}
		else
			path = build_path(sh->lst_env, av[i]);
	}
	else
		return (cd_error(0, NULL));
	return (change_directory(&sh->lst_env, path, follow_sl));
}
