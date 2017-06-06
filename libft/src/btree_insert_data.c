/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 19:05:36 by fhuang            #+#    #+#             */
/*   Updated: 2016/09/02 14:05:39 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree **root, void *item,\
			int (*cmpf)(void *, void *))
{
	t_btree		*new;

	if (root == NULL)
		if ((root = (t_btree**)ft_memalloc(sizeof(t_btree*))) == NULL)
			return ;
	if ((new = btree_create_node(item)) == NULL)
		return ;
	if (*root == NULL)
		*root = new;
	else
	{
		cmpf(new, root) > 0 ? btree_insert_data(&(*root)->left, item, cmpf) :\
			btree_insert_data(&(*root)->right, item, cmpf);
	}
}
