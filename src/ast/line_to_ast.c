/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 17:11:54 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/06 17:19:01 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ast.h"

t_ast		*line_to_ast(char *line)
{
	t_ast	*tree;

	tree = NULL;
	if (!(tree = ast_create_tree(line)))
		return (NULL);
	if (!ast_parse_tree(tree))
	{
		ast_destroy_tree(tree);
		return (NULL);
	}
	if (!ast_to_cmdwr(&tree))
		return (NULL);
	return (tree);
}
