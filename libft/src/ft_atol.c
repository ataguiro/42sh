/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:19:07 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/12 15:21:47 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long			ft_atol(const char *str)
{
	long		res;
	const char	*ptr;
	int			negatif;

	res = 0;
	ptr = str;
	while (*ptr && ft_isspace(*ptr))
		ptr++;
	negatif = *ptr == '-' ? -1 : 1;
	if (*ptr == '-' || *ptr == '+')
		ptr++;
	while (*ptr && ft_isdigit(*ptr))
	{
		res *= 10;
		res += negatif * (*ptr - '0');
		ptr++;
	}
	return (res);
}
