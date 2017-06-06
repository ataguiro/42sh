/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_is_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:40:17 by yfuks             #+#    #+#             */
/*   Updated: 2017/02/03 16:32:53 by tpoac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libft.h"
#include "ft_42sh.h"
#include "tools.h"

static int	is_binary_builtin(t_exec *ex, t_shell *sh, char **command)
{
	char	*executable;

	executable = ft_strjoin(sh->bin_path, command[0]);
	if (exec_is_file(executable))
	{
		ex->command = executable;
		return (1);
	}
	ft_strdel(&executable);
	return (0);
}

static	int	is_builtin_notbinary(t_exec *ex, char **command)
{
	char	**builtins_list;
	int		i;

	if (!(builtins_list = ft_strsplit(BUILTIN, ' ')))
		return (0);
	i = 0;
	while (builtins_list[i])
	{
		if (ft_strcmp(command[0], builtins_list[i]) == 0)
		{
			tl_freedoubletab(builtins_list);
			ex->builtin_not_binary = 1;
			return (1);
		}
		i++;
	}
	tl_freedoubletab(builtins_list);
	return (0);
}

int			exec_is_builtin(t_exec *ex, t_shell *sh, char **command)
{
	if (!command)
		return (0);
	if (!ft_strchr(command[0], '/') && is_binary_builtin(ex, sh, command))
		return (1);
	if (!ft_strchr(command[0], '/') && is_builtin_notbinary(ex, command))
		return (1);
	return (0);
}
