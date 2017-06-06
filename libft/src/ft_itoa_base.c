/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:40:41 by fhuang            #+#    #+#             */
/*   Updated: 2016/10/28 16:35:40 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_n(unsigned int n, int base)
{
	int					ret;

	ret = 1;
	while (n / base)
	{
		ret++;
		n /= base;
	}
	return (ret);
}

char		*ft_itoa_base(int n, int base)
{
	char const			pattern[] = "0123456789abcdef";
	char				*ret;
	unsigned int		uin;
	int					len;
	bool				neg;

	neg = (base == 10 && n < 0) ? 1 : 0;
	neg == false ? ABS(n) : 1;
	uin = (unsigned int)n;
	len = count_n(uin, base) + neg;
	if ((ret = ft_strnew(len)) == NULL)
		return (NULL);
	while (len-- >= 0)
	{
		ret[len] = pattern[uin % base];
		uin /= base;
	}
	neg ? ret[0] = '-' : 0;
	return (ret);
}
