/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:43:18 by yfuks             #+#    #+#             */
/*   Updated: 2016/12/08 15:55:16 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include <sys/wait.h>
#include <stdlib.h>
#include "libft.h"

static	int		get_command_status_code(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	else if (WIFSTOPPED(status))
		return (WSTOPSIG(status));
	return (0);
}

static	int		rp_error(char *name, char *error, int code)
{
	env_put_error(name, error);
	return (code);
}

int				env_execute_command(char **env, char **av, int index)
{
	pid_t	id;
	int		tmp;
	char	*executable;

	if (!(executable = env_get_command_path(env, av[index])))
		return (rp_error(av[index], "No such file or directory", NOTFOUND));
	if (!env_is_executable(executable))
	{
		free(executable);
		return (rp_error(av[index], "Permission denied", CANNOTINVOKE));
	}
	id = fork();
	if (id > 0)
	{
		waitpid(0, &tmp, WUNTRACED | WCONTINUED);
		free(executable);
		return (get_command_status_code(tmp));
	}
	else if (id == 0)
	{
		execve(executable, &av[index], env);
		exit(NOTFOUND);
	}
	return (0);
}
