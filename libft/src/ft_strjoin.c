/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:02:02 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/13 16:02:23 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sfinal;
	int		i;
	int		j;

	if ((sfinal = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		sfinal[i] = s1[i];
	j = 0;
	while (s2[j])
		sfinal[i++] = s2[j++];
	return (sfinal);
}
