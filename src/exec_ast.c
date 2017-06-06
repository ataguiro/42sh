/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:20:49 by yfuks             #+#    #+#             */
/*   Updated: 2017/02/01 16:10:22 by tpoac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "ast.h"
#include <sys/wait.h>
#include <unistd.h>
#include "libft.h"
#include "expansion.h"

static	int	exec_and(t_shell *sh, t_ast *ast)
{
	if (ast->left)
		exec_ast(sh, ast->left);
	else
		exec_redirection(sh, ast->cmd1);
	if (sh->last_return == 0 && ast->right)
		exec_ast(sh, ast->right);
	else if (sh->last_return == 0 && ast->cmd2)
		exec_redirection(sh, ast->cmd2);
	else if (sh->last_return == 0 && ast->cmd1)
		exec_redirection(sh, ast->cmd1);
	return (sh->last_return);
}

static	int	exec_or(t_shell *sh, t_ast *ast)
{
	if (ast->left)
		exec_ast(sh, ast->left);
	else
		exec_redirection(sh, ast->cmd1);
	if (sh->last_return != 0 && ast->right)
		exec_ast(sh, ast->right);
	else if (sh->last_return != 0 && ast->cmd2)
		exec_redirection(sh, ast->cmd2);
	else if (sh->last_return != 0 && ast->cmd1)
		exec_redirection(sh, ast->cmd1);
	return (sh->last_return);
}

int			exec_pipes(t_shell *sh, t_ast *ast)
{
	pid_t	id;
	int		tmp;

	id = fork();
	if (id > 0)
	{
		waitpid(-1, &tmp, WUNTRACED | WCONTINUED);
		sh->last_return = get_command_status_code(tmp);
		return (sh->last_return);
	}
	else if (id == 0)
		exec_pipe(sh, &ast);
	return (0);
}

int			exec_ast(t_shell *sh, t_ast *ast)
{
	if (ast->operator == AND)
		return (exec_and(sh, ast));
	if (ast->operator == OR)
		return (exec_or(sh, ast));
	if (ast->operator == COMMAND || ast->operator == REDIRECTION)
		return (exec_redirection(sh, ast->cmd1));
	if (ast->operator == PIPE)
		return (exec_pipes(sh, ast));
	return (0);
}
