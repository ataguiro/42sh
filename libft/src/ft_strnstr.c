/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:10:21 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/02 16:21:07 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		len;

	len = ft_strlen(s2);
	if (len == 0)
		return ((char*)s1);
	while (*s1 && n >= len)
	{
		n--;
		if (!(ft_strncmp(s1, s2, len)))
			return ((char*)s1);
		s1++;
	}
	return (0);
}
