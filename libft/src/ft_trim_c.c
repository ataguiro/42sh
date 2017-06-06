/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:29:42 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/04 11:30:04 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trim_c(char const *s, char c)
{
	char	*swb;
	int		i;
	int		j;
	int		end;

	j = 0;
	i = 0;
	end = ft_strlen(s) - 1;
	while (s[i] == c)
	{
		i++;
		if (s[i] == '\0')
			return (((char*)s) + i);
	}
	while (s[end] == c)
		end--;
	swb = ft_memalloc(sizeof(char) * (end - i + 1));
	while (i <= end)
		swb[j++] = s[i++];
	swb[j] = '\0';
	return (swb);
}
