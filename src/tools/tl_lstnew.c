/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:18:30 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/01 21:00:52 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*tl_lstnew(void *content, size_t size)
{
	t_list		*new;

	new = NULL;
	if (!(new = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	new->content_size = size;
	new->content = content;
	new->next = NULL;
	return (new);
}
