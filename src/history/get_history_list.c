/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_history_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:29:27 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/18 21:25:23 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**get_full_list(void)
{
	static t_list	*history = NULL;

	if (!history)
		history = ft_lstnew(NULL, 0);
	return (&history);
}

t_list	**get_new_list(void)
{
	static t_list	*history = NULL;

	if (!history)
		history = *get_full_list();
	return (&history);
}
