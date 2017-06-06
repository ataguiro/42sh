/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_strnupto.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoac <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:28:27 by tpoac             #+#    #+#             */
/*   Updated: 2017/01/24 17:29:17 by tpoac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int			tl_strnupto(const char *str, const char *charset, int n)
{
	size_t	i;
	size_t	j;
	int		t;

	i = 0;
	j = 0;
	t = 0;
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
		{
			if (t == n)
				return (i + 1);
			t++;
		}
		j++;
	}
	return (0);
}
