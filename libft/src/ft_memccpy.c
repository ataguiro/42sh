/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:44:06 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/02 16:16:12 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	c_char;
	unsigned char	*ptr;
	unsigned char	*dst_char;
	unsigned char	*src_char;

	i = 0;
	c_char = (unsigned char)c;
	dst_char = (unsigned char*)dst;
	src_char = (unsigned char*)src;
	ptr = NULL;
	while (i < n)
	{
		dst_char[i] = src_char[i];
		i++;
		if (src_char[i - 1] == c_char)
			return (&dst_char[i]);
	}
	return (ptr);
}
