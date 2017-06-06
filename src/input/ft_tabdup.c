/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:59:01 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/19 14:19:13 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

char	**ft_tabdup(char **tab)
{
	char	**dup;
	size_t	size;
	size_t	i;
	size_t	j;

	size = tl_arrlen(tab) + 1;
	i = 0;
	j = 0;
	if (!(dup = (char **)ft_memalloc(sizeof(char *) * size)))
		return (NULL);
	while (tab[i])
	{
		if (tab[i][0])
		{
			dup[j] = strdup_input(tab[i]);
			j++;
		}
		i++;
	}
	return (dup);
}
