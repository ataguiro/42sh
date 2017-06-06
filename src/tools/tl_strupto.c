/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_strupto.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoac <tpoac@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 23:52:38 by tpoac             #+#    #+#             */
/*   Updated: 2017/01/22 16:37:15 by tpoac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

size_t		tl_strupto(const char *str, const char *charset)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str && !charset)
		return (0);
	while (str[i])
	{
		if (!charset[j])
		{
			j = 0;
			i++;
		}
		if (str[i] == charset[j])
			return (i + 1);
		j++;
	}
	return (0);
}
