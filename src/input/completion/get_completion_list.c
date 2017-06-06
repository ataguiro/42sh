/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_completio_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:37:19 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/23 17:37:44 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**get_list_completion(void)
{
	static t_list	*lst_completion = NULL;

	return (&lst_completion);
}

t_list	**get_cursor_completion(void)
{
	static t_list	*cursor = NULL;

	return (&cursor);
}
