/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:06:48 by fhuang            #+#    #+#             */
/*   Updated: 2015/11/30 09:54:38 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c_char;
	unsigned char	*s_char;
	size_t			i;

	c_char = (unsigned char)c;
	s_char = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (s_char[i] == c_char)
			return (&s_char[i]);
		i++;
	}
	return (NULL);
}
