/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_execute_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:46:09 by yfuks             #+#    #+#             */
/*   Updated: 2017/02/05 17:25:22 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "tools.h"
#include "builtins.h"
#include "environment.h"

static	const	t_bnb	g_bnb[] = {
	{"cd", builtin_cd},
	{"exit", builtin_exit},
	{"read", builtin_read},
	{"unsetenv", builtin_unsetenv},
	{"setenv", builtin_setenv},
	{"export", builtin_export},
	{"unset", builtin_unset},
	{"alias", builtin_alias},
	{"unalias", builtin_unalias},
	{"history", builtin_history},
	{0, 0}
};

pid_t			g_id = -1;

static	int		execute_bnb(t_shell *sh, char **command)
{
	int		i;

	i = 0;
	while (g_bnb[i].builtin)
	{
		if (ft_strcmp(g_bnb[i].builtin, command[0]) == 0)
		{
			sh->last_return = g_bnb[i].function(sh,\
				tl_arrlen(command), command);
			return (sh->last_return);
		}
		i++;
	}
	return (0);
}

int				exec_execute_command(t_exec *ex, t_shell *sh, char **command)
{
	int				tmp;
	char			**env;

	if (ex->builtin_not_binary)
		return (execute_bnb(sh, command));
	sh_setenv(&sh->lst_env, "_", ex->command);
	env = lstenv_to_tab(sh->lst_env);
	if ((g_id = fork()) > 0)
	{
		waitpid(0, &tmp, WUNTRACED | WCONTINUED);
		sh->last_return = get_command_status_code(tmp);
		free(env);
		return (sh->last_return);
	}
	else if (g_id == 0)
	{
		execve(ex->command, command, env);
		exit(NOTFOUND);
	}
	return (0);
}
