/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:19:21 by yfuks             #+#    #+#             */
/*   Updated: 2017/01/18 19:38:29 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <pwd.h>
#include "ft_42sh.h"
#include "tools.h"
#include "environment.h"
#include "history.h"
#include "expansion.h"
#include "input.h"

/*
**		This file is initalizing the shell. (Termios and environment).
*/

static int	copy_environment(t_variable **lst_env)
{
	extern char	**environ;
	int			i;

	*get_home() = getpwuid(getuid())->pw_dir;
	i = 0;
	while (environ && environ[i])
	{
		create_elem(lst_env, environ[i]);
		++i;
	}
	return (GOOD);
}

static int	increment_shlvl(t_variable **lst_env)
{
	char	*tmp;
	int		shlvl;

	if ((tmp = sh_getenv(*lst_env, "SHLVL")))
	{
		shlvl = ft_atoi(tmp);
		if (!(tmp = ft_itoa(++shlvl)))
			return (ERROR);
	}
	else if (!(tmp = ft_strdup("1")))
		return (ERROR);
	if (!sh_setenv(lst_env, "SHLVL", tmp))
	{
		ft_strdel(&tmp);
		return (ERROR);
	}
	ft_strdel(&tmp);
	return (GOOD);
}

static int	set_bin_path(char **bin_path, char *av_0)
{
	char	buffer[_POSIX_PATH_MAX + 1];
	char	*tmp;

	if (!getcwd(buffer, _POSIX_PATH_MAX + 1))
		return (ERROR);
	tmp = ft_strdup(av_0);
	ft_strclr(tmp + ft_strlen(tmp) - 4);
	tmp = ft_strcat(tmp, "bin/");
	if (!(*bin_path = tl_str3join(buffer,\
		buffer[ft_strlen(buffer) - 1] == '/' ? "" : "/", tmp)))
	{
		ft_strdel(&tmp);
		return (ERROR);
	}
	ft_strdel(&tmp);
	return (GOOD);
}

static int	set_default(t_variable **lst_env)
{
	if (!increment_shlvl(lst_env))
		return (ERROR);
	if (!sh_getenv(*lst_env, "PATH"))
		if (!sh_setenv(lst_env, "PATH", DEFAULT_PATH))
			return (ERROR);
	sh_setenv(lst_env, "SHELL", "./42sh");
	return (GOOD);
}

int			init_shell(t_shell *sh, char *av_0)
{
	ft_bzero(sh, sizeof(t_shell));
	if (!copy_environment(&sh->lst_env))
		return (ERROR);
	if (!set_bin_path(&sh->bin_path, av_0))
		return (ERROR);
	set_default(&sh->lst_env);
	init_history_list();
	import_shrc(sh);
	return (GOOD);
}
