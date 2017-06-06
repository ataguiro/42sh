/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:11:26 by fhuang            #+#    #+#             */
/*   Updated: 2016/09/02 14:13:49 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		end;

	i = 0;
	end = ft_strlen(s) - 1;
	while (s[i] != '\0' && ft_space((int)s[i]) == 1)
		i++;
	if (s[i] == '\0')
		return (ft_strdup((char*)s + i));
	while (ft_space((int)s[end]) == 1)
		end--;
	return (ft_strndup((char*)s + i, ++end - i));
}
