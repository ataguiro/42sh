/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_destroy_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:05:13 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/05 16:49:35 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "libft.h"

void	ast_destroy_tree(t_ast *tree)
{
	if (!tree)
		return ;
	ast_destroy_tree(tree->left);
	ast_destroy_tree(tree->right);
	tree->operator = 0;
	if (tree->str)
		ft_strdel(&tree->str);
	if (tree->cmd1)
	{
		free_heredocs(tree->cmd1);
		ast_free_cmdwr(&tree->cmd1);
	}
	if (tree->cmd2)
	{
		free_heredocs(tree->cmd2);
		ast_free_cmdwr(&tree->cmd2);
	}
	ft_memdel((void*)&tree);
}
