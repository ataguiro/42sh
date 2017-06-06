/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_through_commands.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:18:37 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/05 16:43:16 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ast.h"
#include "expansion.h"
#include "execution.h"
#include "tools.h"
#include "ft_42sh.h"

pid_t			g_heredoc_pid = -1;

static int	handle_expansion(t_shell *sh, t_cmdwr *cmd)
{
	size_t		i;
	t_list		*lst_tab;
	t_list		*result;

	i = 0;
	lst_tab = tl_tabtolst(cmd->command);
	tl_freedoubletab(cmd->command);
	result = glob_substitution(&lst_tab);
	cmd->command = tl_lsttotab(result);
	tl_nodefree(&lst_tab);
	tl_nodefree(&result);
	while (cmd->command && cmd->command[i])
	{
		if (!(cmd->command[i] = substitute(sh, cmd->command[i])))
			return (ERROR);
		++i;
	}
	return (GOOD);
}

static int	loop_through_ast(t_shell *sh, t_ast *tree)
{
	if (!tree)
		return (GOOD);
	if (tree->cmd1)
		if (!handle_expansion(sh, tree->cmd1))
			return (ERROR);
	if (tree->cmd2)
		if (!handle_expansion(sh, tree->cmd2))
			return (ERROR);
	if (!loop_through_ast(sh, tree->left))
		return (ERROR);
	return (loop_through_ast(sh, tree->right));
}

void		loop_through_commands(t_shell *sh, t_list *lst_commands)
{
	t_list		*ptr;

	ptr = lst_commands;
	if (!get_heredocs(sh, &ptr))
		return ;
	while (ptr)
	{
		if (!loop_through_ast(sh, ptr->content))
			return ;
		exec_ast(sh, ptr->content);
		ptr = ptr->next;
	}
}
