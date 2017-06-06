/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:59:33 by cjacquem          #+#    #+#             */
/*   Updated: 2017/01/14 16:03:36 by cjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "libft.h"
#include "tools.h"

t_list		*ast_to_lst(t_ast **ast)
{
	t_ast	*cursor;
	t_list	*begin;

	cursor = *ast;
	begin = NULL;
	while (cursor)
	{
		if (cursor->cmd2)
		{
			if (!begin)
				begin = tl_lstnew(cursor->cmd2, sizeof(cursor->cmd2));
			else
				ft_lstadd(&begin, tl_lstnew(cursor->cmd2, \
													sizeof(cursor->cmd2)));
		}
		if (!begin)
			begin = tl_lstnew(cursor->cmd1, sizeof(cursor->cmd1));
		else
			ft_lstadd(&begin, tl_lstnew(cursor->cmd1, sizeof(cursor->cmd1)));
		cursor = cursor->left;
	}
	return (begin);
}
