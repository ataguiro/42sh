/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_is_standalone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:25:35 by yfuks             #+#    #+#             */
/*   Updated: 2017/02/03 16:34:26 by tpoac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "tools.h"
#include "libft.h"

int	exec_is_standalone(t_exec *ex, char **command, char **paths)
{
	int		i;
	char	*executable;

	if (command && ft_strchr(command[0], '/') && exec_is_file(command[0]))
	{
		ex->command = ft_strdup(command[0]);
		return (1);
	}
	if (command && !ft_strchr(command[0], '/'))
	{
		i = 0;
		while (paths && paths[i])
		{
			executable = tl_str3join(paths[i], "/", command[0]);
			if (exec_is_file(executable))
			{
				ex->command = executable;
				return (1);
			}
			ft_strdel(&executable);
			i++;
		}
	}
	return (0);
}
