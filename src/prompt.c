/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:08:58 by yfuks             #+#    #+#             */
/*   Updated: 2017/01/25 14:33:31 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <limits.h>
#include "ft_42sh.h"
#include "environment.h"
#include "libft.h"
#include "input.h"

static	char	*get_path_from_pwd(void)
{
	char	*pwd;
	char	*home;
	char	*chain;
	char	*tmp;
	int		i;

	pwd = getcwd(NULL, _POSIX_PATH_MAX);
	home = getpwuid(getuid())->pw_dir;
	if (!home || !pwd)
		return (NULL);
	if (!ft_strstr(pwd, home))
		return (pwd);
	i = 0;
	while (pwd[i] && home[i] && pwd[i] == home[i])
		++i;
	tmp = ft_strdup(&pwd[i]);
	chain = ft_strjoin("~", tmp);
	ft_strdel(&tmp);
	ft_strdel(&pwd);
	return (chain);
}

int				prompt(void)
{
	char	*pwd;
	char	*user;
	int		length;

	if ((user = getpwuid(getuid())->pw_name))
	{
		ft_putstr("\033[1;32m");
		ft_putstr(user);
		ft_putstr("\x1b[0m ");
	}
	else
		ft_putchar('$');
	length = 2 + (user ? ft_strlen(user) : 1);
	if ((pwd = get_path_from_pwd()))
	{
		ft_putstr(pwd);
		length += ft_strlen(pwd);
		ft_strdel(&pwd);
	}
	*search_mode() ? ft_putstr("\033[1;34m (i-search)\033[0m") : 0;
	*search_mode() ? length += 11 : 0;
	ft_putstr("> ");
	*prompt_len() = length;
	return (length);
}
