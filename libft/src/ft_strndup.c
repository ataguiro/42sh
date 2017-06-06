/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:07:56 by fhuang            #+#    #+#             */
/*   Updated: 2016/06/12 20:38:50 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dst;

	if (!(dst = (char*)ft_memalloc(sizeof(char) * (n + 1))))
		return (NULL);
	dst = ft_strncpy(dst, src, n);
	return (dst);
}
