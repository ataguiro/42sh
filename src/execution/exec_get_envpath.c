/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_get_envpath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:11:56 by yfuks             #+#    #+#             */
/*   Updated: 2016/12/14 13:56:45 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "ft_42sh.h"
#include "libft.h"

char	**exec_get_envpath(t_shell *sh)
{
	char	*path;
	char	**split;

	if (!(path = sh_getenv(sh->lst_env, "PATH")))
		return (ERROR);
	split = ft_strsplit(path, ':');
	return (split);
}
