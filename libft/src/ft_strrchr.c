/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:17:54 by fhuang            #+#    #+#             */
/*   Updated: 2016/06/12 19:00:21 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s_char;

	s_char = (char*)s;
	i = ft_strlen(s);
	if (c == 0)
	{
		while (*s_char)
			s_char++;
		return (s_char);
	}
	while (i >= 0)
	{
		if (s[i] == c)
			return (s_char + i);
		i--;
	}
	return (NULL);
}
