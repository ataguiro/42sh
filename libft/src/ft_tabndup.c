/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 14:39:48 by fhuang            #+#    #+#             */
/*   Updated: 2016/07/13 15:19:34 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabndup(char **tab, int n)
{
	char	**ret;
	int		i;

	if ((ret = ft_memalloc(sizeof(char*) * (n + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < n && tab[i])
	{
		if ((ret[i] = ft_strdup(tab[i])) == NULL)
			return (NULL);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
