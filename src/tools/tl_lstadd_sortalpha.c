/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_lstadd_sortalpha.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 21:09:54 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/24 21:38:55 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		tl_lstadd_sortalpha(t_list **lst, t_list *new)
{
	t_list	*ptr;
	t_list	*prev;

	ptr = *lst;
	prev = NULL;
	while (ptr)
	{
		if (ft_strcmp(ptr->content, new->content) > 0)
			break ;
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr == *lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else if (prev->next == NULL)
		prev->next = new;
	else
	{
		new->next = prev->next;
		prev->next = new;
	}
}
