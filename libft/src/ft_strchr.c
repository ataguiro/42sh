/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:47:28 by fhuang            #+#    #+#             */
/*   Updated: 2016/07/03 22:57:51 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	o;
	char	*s_char;

	o = (char)c;
	s_char = (char*)s;
	i = 0;
	if (c == 0)
	{
		while (*s_char)
			s_char++;
		return (s_char);
	}
	while (s_char[i])
	{
		if (s_char[i] == o)
			return (&s_char[i]);
		i++;
	}
	return (0);
}
