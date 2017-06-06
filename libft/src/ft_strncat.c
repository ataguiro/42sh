/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:15:37 by fhuang            #+#    #+#             */
/*   Updated: 2016/06/18 23:25:59 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		len_s1;

	len_s1 = ft_strlen(s1);
	ft_strncpy(s1 + len_s1, s2, n);
	s1[len_s1 + n] = '\0';
	return (s1);
}
