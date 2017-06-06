/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 19:25:07 by fhuang            #+#    #+#             */
/*   Updated: 2016/06/05 22:59:14 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		btree_level_count(t_btree *root)
{
	size_t		left_lvl;
	size_t		right_lvl;

	if (root == NULL)
		return (0);
	left_lvl = btree_level_count(root->left);
	right_lvl = btree_level_count(root->right);
	return (left_lvl > right_lvl ? left_lvl + 1 : right_lvl + 1);
}
