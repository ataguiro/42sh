/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 17:56:25 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/14 17:10:32 by cjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <sys/stat.h>
#include "environment.h"
#include "builtins.h"
#include "libft.h"

static void	set_pwd(t_variable **lst_env, char *path, _Bool follow_sl)
{
	struct stat	buf;
	char		*tmp;

	if ((tmp = sh_getenv(*lst_env, "PWD")))
		sh_setenv(lst_env, "OLDPWD", tmp);
	tmp = NULL;
	lstat(path, &buf);
	if (follow_sl == 0 || S_ISLNK(buf.st_mode) != 1)
	{
		if ((tmp = getcwd(tmp, _POSIX_PATH_MAX)))
		{
			sh_setenv(lst_env, "PWD", tmp);
			ft_strdel(&tmp);
		}
	}
	else
		sh_setenv(lst_env, "PWD", path);
}

int			change_directory(t_variable **lst_env, char *path, _Bool follow_sl)
{
	struct stat	buf;
	int			ret;

	if (!path)
		return (1);
	ret = 0;
	if (access(path, F_OK) == -1)
		ret = cd_error(3, path);
	stat(path, &buf);
	if (!ret && S_ISDIR(buf.st_mode) != 1)
		ret = cd_error(4, path);
	if (!ret && access(path, X_OK) == -1)
		ret = cd_error(5, path);
	if (!ret && chdir(path) == -1)
	{
		ft_strdel(&path);
		return (1);
	}
	if (!ret)
		set_pwd(lst_env, path, follow_sl);
	ft_strdel(&path);
	return (ret);
}
