/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 17:05:42 by fhuang            #+#    #+#             */
/*   Updated: 2016/09/07 12:12:06 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *in, char *where, char *bywhat)
{
	char	*ret;
	char	*tmp;
	int		len;

	if ((tmp = ft_strstr(in, where)) != NULL)
	{
		len = ft_strlen(in) - ft_strlen(where) + ft_strlen(bywhat);
		ret = ft_strnew(len);
		if (ret == NULL)
			return (NULL);
		ret = ft_strncat(ret, in, (size_t)(tmp - in));
		ret = ft_strcat(ret, bywhat);
		tmp += ft_strlen(where);
		ret = ft_strcat(ret, tmp);
		return (ret);
	}
	return (ft_strdup(""));
}
