/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:52:02 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/09 16:14:04 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		n;
	size_t		len_dst;
	size_t		len_src;

	n = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size > len_dst)
	{
		n = size - len_dst - 1;
		ft_strncpy(&dst[len_dst], src, n);
		return (len_dst + len_src);
	}
	else if (size < len_dst)
		return (size + len_src);
	return (0);
}
