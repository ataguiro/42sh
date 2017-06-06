/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:07:28 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/18 18:53:02 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "input.h"

int		history_clear_list(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (tmp->content)
			free(tmp->content);
		tmp->content = NULL;
		if (tmp)
			free(tmp);
		tmp = NULL;
	}
	*get_full_list() = NULL;
	*get_new_list() = NULL;
	return (0);
}
