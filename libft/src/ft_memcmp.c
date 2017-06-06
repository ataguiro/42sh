/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:10:40 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/02 16:16:52 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*s1_char;
	const char	*s2_char;

	i = 0;
	s1_char = (const char*)s1;
	s2_char = (const char*)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1_char[i] != s2_char[i])
		{
			return (((unsigned char*)s1_char)[i]
				- ((unsigned char*)s2_char)[i]);
		}
		i++;
	}
	return (0);
}
