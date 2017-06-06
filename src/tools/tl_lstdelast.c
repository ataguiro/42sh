/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_lstdelast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:19:10 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/01 14:19:55 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ast.h"

void		tl_lstdelast(t_list **lst)
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = *lst;
	tmp = NULL;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ast_destroy_tree(tmp->content);
		tmp->content_size = 0;
		free(tmp);
		tmp = NULL;
	}
}
