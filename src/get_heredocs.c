/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredocs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 23:35:38 by yfuks             #+#    #+#             */
/*   Updated: 2017/01/13 15:04:32 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "execution.h"
#include "ast.h"

static int	retrieve_heredocs(t_shell *sh, t_cmdwr *cmd)
{
	t_redirections		*cursor;

	cursor = cmd->redirs;
	while (cursor)
	{
		if (cursor->type & DOUBLE_LEFT_REDIRECT)
			get_heredoc(sh, cmd, cursor);
		cursor = cursor->next;
	}
	return (GOOD);
}

static int	get_heredocs_from_ast(t_shell *sh, t_ast *ast)
{
	if (ast->cmd1)
		retrieve_heredocs(sh, ast->cmd1);
	if (ast->cmd2)
		retrieve_heredocs(sh, ast->cmd2);
	if (ast->left)
		return (get_heredocs_from_ast(sh, ast->left));
	if (ast->right)
		return (get_heredocs_from_ast(sh, ast->right));
	return (GOOD);
}

int			get_heredocs(t_shell *sh, t_list **list)
{
	t_list	*cursor;

	cursor = *list;
	while (cursor)
	{
		get_heredocs_from_ast(sh, cursor->content);
		cursor = cursor->next;
	}
	return (GOOD);
}
