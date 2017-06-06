/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_insert_elem_in_tree.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:27:36 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/08 15:29:59 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "libft.h"

#define IS_AND(x) ((x)->operator == AND)
#define IS_OR(x) ((x)->operator == OR)

static void	new_is_command(t_ast **root, t_ast *new)
{
	if ((*root)->left == NULL)
		ast_insert_elem_in_tree(&(*root)->left, new);
	else
		ast_insert_elem_in_tree(&(*root)->right, new);
}

static void	new_is_operator(t_ast **root, t_ast *new)
{
	if ((*root)->operator == COMMAND || new->operator <= (*root)->operator ||\
		(IS_AND(new) && IS_OR((*root))) || (IS_OR(new) && IS_AND((*root))))
	{
		new->left = *root;
		*root = new;
	}
	else if (new->operator > (*root)->operator)
	{
		if ((*root)->right && (*root)->right->operator != COMMAND)
			ast_insert_elem_in_tree(&(*root)->right, new);
		else
		{
			new->left = (*root)->right;
			(*root)->right = new;
		}
	}
}

void		ast_insert_elem_in_tree(t_ast **root, t_ast *new)
{
	if (*root == NULL)
		*root = new;
	else if (new->operator == COMMAND)
		new_is_command(root, new);
	else
		new_is_operator(root, new);
}
