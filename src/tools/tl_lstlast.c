/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:36:57 by cjacquem          #+#    #+#             */
/*   Updated: 2016/11/24 10:37:21 by cjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"

t_list		*tl_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	return (!lst->next ? lst : tl_lstlast(lst->next));
}
