/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3cat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 15:22:48 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/31 11:07:18 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str3cat(char *s1, char *s2, char *s3)
{
	char	*ret;

	if (!s1 || !s2 || !s3)
		return (NULL);
	ret = ft_strndup(s1, ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3));
	if (ret == NULL)
		return (NULL);
	ret = ft_strcat(ret, s2);
	ret = ft_strcat(ret, s3);
	return (ret);
}
