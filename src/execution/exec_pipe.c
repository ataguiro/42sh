/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:01:52 by yfuks             #+#    #+#             */
/*   Updated: 2017/01/14 16:50:27 by cjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "execution.h"
#include "ast.h"
#include "libft.h"
#include "tools.h"

static void		parent_process(t_shell *sh, t_pipe box, int *fd_in, \
														t_list **cursor)
{
	int		tmp;

	close(box.pipefd[1]);
	*fd_in = box.pipefd[0];
	if (!(*cursor)->next)
	{
		waitpid(box.id, &tmp, WUNTRACED | WCONTINUED);
		sh->last_return = get_command_status_code(tmp);
		tl_lstfree(&box.begin);
		exit(sh->last_return);
	}
	else
		*cursor = (*cursor)->next;
}

static void		child_process(t_shell *sh, t_pipe box, int fd_in,\
															t_list *cursor)
{
	dup2(fd_in, 0);
	if (cursor->next)
		dup2(box.pipefd[1], 1);
	close(box.pipefd[0]);
	exit(exec_redirection(sh, (t_cmdwr *)cursor->content));
}

void			exec_pipe(t_shell *sh, t_ast **ast)
{
	t_pipe	box;
	int		fd_in;
	t_list	*cursor;

	box.begin = ast_to_lst(ast);
	cursor = box.begin;
	fd_in = 0;
	while (cursor)
	{
		pipe(box.pipefd);
		box.id = fork();
		if (box.id > 0)
			parent_process(sh, box, &fd_in, &cursor);
		else if (box.id == 0)
			child_process(sh, box, fd_in, cursor);
	}
}
