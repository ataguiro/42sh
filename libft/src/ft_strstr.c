/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:10:21 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/09 16:13:13 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		len;
	int			i;

	i = 0;
	len = ft_strlen(s2);
	if (len == 0)
		return ((char*)s1);
	while (s1[i])
		if (ft_strncmp(s1 + i++, s2, len) == 0)
			return ((char*)s1 + i - 1);
	return (NULL);
}
