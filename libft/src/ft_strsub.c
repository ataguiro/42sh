/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:54:45 by fhuang            #+#    #+#             */
/*   Updated: 2016/06/12 18:59:19 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*troncon;
	size_t	j;

	troncon = ft_strnew(len);
	if (troncon == NULL)
		return (NULL);
	j = 0;
	while (j < len)
	{
		troncon[j] = s[start + j];
		j++;
	}
	troncon[j] = '\0';
	return (troncon);
}
