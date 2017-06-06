/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_nodefree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:54:52 by cjacquem          #+#    #+#             */
/*   Updated: 2017/02/05 14:00:19 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		tl_nodefree(t_list **begin)
{
	t_list	*cursor;
	t_list	*tofree;

	cursor = *begin;
	while (cursor)
	{
		tofree = cursor;
		cursor = cursor->next;
		free(tofree);
	}
}
