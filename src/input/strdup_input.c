/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 15:25:34 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/23 18:15:58 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

char	*strdup_input(char *src)
{
	int		i;
	int		j;
	char	*dest;

	if (!src || !src[0])
		return (ft_strnew(0));
	dest = ft_strnew(ft_strlen(src));
	j = 0;
	i = 0;
	while (src[i])
	{
		if ((unsigned char)src[i] != 127)
		{
			dest[j] = src[i];
			j++;
		}
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
