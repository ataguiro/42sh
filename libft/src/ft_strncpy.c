/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:07:56 by fhuang            #+#    #+#             */
/*   Updated: 2016/06/18 23:21:48 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (n && src[i])
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	while (n > 0)
	{
		dst[i++] = '\0';
		n--;
	}
	return (dst);
}
