/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:20:03 by fhuang            #+#    #+#             */
/*   Updated: 2016/07/04 03:10:39 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_str(const char *s, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			i++;
			if (s[i] == c || s[i] == '\0')
				n++;
		}
	}
	return (n);
}

static int	count_c(const char *s, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] != c)
		{
			i++;
			n++;
			if (s[i] == c || s[i] == '\0')
				break ;
		}
		if (n)
			break ;
		i++;
	}
	return (n);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	j = 0;
	if ((tab = (char**)ft_memalloc(sizeof(char*) * (count_str(s, c) + 1))))
	{
		i = 0;
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			if (count_c(s + i, c))
				if (!(tab[j++] = ft_strndup(s + i, count_c(s + i, c))))
					return (NULL);
			while (s[i] && s[i] != c)
				i++;
		}
		tab[j] = NULL;
		return (tab);
	}
	return (NULL);
}
