/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:44:47 by fhuang            #+#    #+#             */
/*   Updated: 2015/11/30 11:33:56 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_char;
	char		*src_char;

	dst_char = (char*)dst;
	src_char = (char*)src;
	if (dst_char < src_char)
		ft_memcpy(dst, src, len);
	else if (dst_char > src_char)
	{
		while (0 < len)
		{
			len--;
			dst_char[len] = src_char[len];
		}
	}
	return ((void*)(dst));
}
