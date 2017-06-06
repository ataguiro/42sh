/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_lstnewstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoac <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:11:01 by tpoac             #+#    #+#             */
/*   Updated: 2017/01/23 16:22:46 by tpoac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

t_list		*tl_lstnewstr(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->content = (content == NULL)
		? NULL : tl_memdup(content, content_size);
	new->content_size = (content == NULL)
		? 0 : content_size;
	new->next = NULL;
	return (new);
}
