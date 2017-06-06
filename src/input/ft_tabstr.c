/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:06:01 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/08 13:06:23 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

char	**ft_tabstr(char **tab, char *str)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		if (!ft_strncmp(tab[i], str, ft_strlen(str)))
			return (&tab[i]);
		i++;
	}
	return (NULL);
}
