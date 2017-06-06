/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:54:42 by fhuang            #+#    #+#             */
/*   Updated: 2016/06/18 23:06:11 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_tabatoi(char **tab)
{
	int		i;
	int		*ret;

	if (!(ret = (int*)ft_memalloc(sizeof(int) * ft_tablen(tab))))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		ret[i] = ft_atoi(tab[i]);
		i++;
	}
	return (ret);
}
