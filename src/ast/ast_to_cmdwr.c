/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_to_cmdwr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:32:18 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/06 13:01:12 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "libft.h"
#include "ft_42sh.h"

#define IS_CMD(x) ((x) && ((x)->operator) == COMMAND)

static void		ast_remove_link(t_ast **root, t_ast **link)
{
	if (!*root)
		return ;
	ast_remove_link(&(*root)->left, link);
	ast_remove_link(&(*root)->right, link);
	if (*root == *link)
	{
		(*link)->operator = 0;
		ft_strdel(&(*link)->str);
		if ((*link)->cmd1)
			ast_free_cmdwr(&(*link)->cmd1);
		if ((*link)->cmd2)
			ast_free_cmdwr(&(*link)->cmd2);
		free(*link);
		*link = NULL;
		*root = NULL;
	}
}

static t_cmdwr	*create_cmdwr(t_ast *ptr)
{
	t_cmdwr	*cmd;

	if (!(cmd = (t_cmdwr*)ft_memalloc(sizeof(t_cmdwr))))
		return (ERROR);
	cmd->command = NULL;
	cmd->redirs = NULL;
	if (!cmdwr_fill_struct(&cmd, ptr->str))
	{
		ast_free_cmdwr(&cmd);
		return (NULL);
	}
	return (cmd);
}

static void		get_cmdwr(t_ast **root, t_ast *ptr)
{
	t_cmdwr	*cmd;

	if (!(cmd = create_cmdwr(ptr)))
		return ;
	if ((*root)->cmd1 == NULL)
		(*root)->cmd1 = cmd;
	else
		(*root)->cmd2 = cmd;
}

int				ast_to_cmdwr(t_ast **root)
{
	t_ast	*ptr;

	if (!*root)
		return (GOOD);
	ptr = NULL;
	if (IS_CMD(*root))
		ptr = *root;
	while (ptr != NULL || (IS_CMD((*root)->left) && (ptr = (*root)->left))\
		|| (IS_CMD((*root)->right) && (ptr = (*root)->right)))
	{
		get_cmdwr(root, ptr);
		if (!IS_CMD(*root))
			ast_remove_link(root, &ptr);
		ptr = NULL;
	}
	ast_to_cmdwr(&(*root)->left);
	ast_to_cmdwr(&(*root)->right);
	return (GOOD);
}
