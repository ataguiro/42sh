/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:29:06 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/08 15:42:39 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*dst_char;
	char			*src_char;

	i = 0;
	dst_char = (char*)dst;
	src_char = (char*)src;
	while (i < n)
	{
		dst_char[i] = src_char[i];
		i++;
	}
	return ((void*)dst_char);
}
