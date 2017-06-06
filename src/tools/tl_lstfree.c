/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <cjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:54:52 by cjacquem          #+#    #+#             */
/*   Updated: 2017/02/05 14:03:29 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		tl_lstfree(t_list **begin)
{
	t_list	*cursor;
	t_list	*tofree;

	cursor = *begin;
	while (cursor)
	{
		tofree = cursor;
		cursor = cursor->next;
		if (tofree->content)
			free(tofree->content);
		tofree->content = NULL;
		tofree->content_size = 0;
		free(tofree);
		tofree = NULL;
	}
	*begin = NULL;
}
