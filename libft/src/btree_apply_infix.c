/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 18:52:58 by fhuang            #+#    #+#             */
/*   Updated: 2016/06/05 23:45:55 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		btree_apply_infix(t_btree *root, void (*applyf)(void*))
{
	if (root)
	{
		btree_apply_infix(root->left, applyf);
		applyf(root);
		btree_apply_infix(root->right, applyf);
	}
}
