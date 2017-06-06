/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:47:57 by fhuang            #+#    #+#             */
/*   Updated: 2016/09/02 14:04:39 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char						*ft_itoa(int n)
{
	char			*ret;
	int				neg;
	int				len;
	long int		uin;

	neg = n < 0 ? 1 : 0;
	uin = (long int)(n);
	if (neg)
		uin *= -1;
	len = ft_nbrlen(uin) + neg;
	if ((ret = ft_strnew(len)) == NULL)
		return (NULL);
	ret[len--] = 0;
	while (len >= 0)
	{
		ret[len] = uin % 10 + '0';
		uin /= 10;
		len--;
	}
	if (neg)
		ret[0] = '-';
	return (ret);
}
