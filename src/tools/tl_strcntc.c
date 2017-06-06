/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_strcntc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoac <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:30:12 by tpoac             #+#    #+#             */
/*   Updated: 2017/01/24 17:31:58 by tpoac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

size_t		tl_strcntc(const char *str, const char *charset)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str || !charset)
		return (0);
	while (str[i])
	{
		if (tl_cis(str[i], charset))
			j++;
		i++;
	}
	return (j);
}
