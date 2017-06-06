/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 13:31:58 by fhuang            #+#    #+#             */
/*   Updated: 2016/06/05 23:47:07 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree			*btree_create_node(void *item)
{
	t_btree		*new;

	new = (t_btree*)ft_memalloc(sizeof(t_btree));
	if (new == NULL)
		return (NULL);
	new->content = item;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
