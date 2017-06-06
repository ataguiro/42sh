/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:23:16 by fhuang            #+#    #+#             */
/*   Updated: 2016/10/13 18:13:55 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdelchar(char *str, int index)
{
	char	*ret;
	int		len;

	len = ft_strlen(str);
	if (!(ret = ft_strnew(len - 1)))
		return (NULL);
	ret = ft_strncat(ret, str, index);
	ret = ft_strcat(ret, str + index + 1);
	return (ret);
}
