/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:43:32 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/11 19:09:55 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include "libft.h"
#include <stdlib.h>

static	void	free_double_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static	int		file_exist(char *filepath)
{
	if (access(filepath, F_OK) != -1)
		return (1);
	return (0);
}

static	char	*join_path_and_command(char *path, char *command_name)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin(path, "/");
	result = ft_strjoin(tmp, command_name);
	free(tmp);
	return (result);
}

static	char	*check_all_paths(char *command_name, char **all_paths)
{
	char	*current_check;
	int		i;

	i = 0;
	if (file_exist(command_name))
		return (ft_strdup(command_name));
	while (all_paths[i])
	{
		current_check = join_path_and_command(all_paths[i], command_name);
		if (file_exist(current_check))
			return (current_check);
		free(current_check);
		i++;
	}
	return (0);
}

char			*env_get_command_path(char **env, char *command_name)
{
	char	*executable;
	char	*env_path;
	char	**all_paths;

	executable = 0;
	if (!(env_path = env_get_paths(env)))
		return (0);
	if (!(all_paths = ft_strsplit(env_path, ':')))
	{
		free(env_path);
		return (0);
	}
	executable = check_all_paths(command_name, all_paths);
	free_double_tab(all_paths);
	free(env_path);
	return (executable);
}
