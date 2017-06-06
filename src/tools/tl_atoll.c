/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 18:06:56 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/16 18:18:32 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	tl_atoll(const char *str)
{
	long long		res;
	int				i;
	int				negatif;

	res = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		++i;
	negatif = str[i] == '-' ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] && ft_isdigit(str[i]))
	{
		res *= 10;
		res += negatif * (str[i] - '0');
		++i;
	}
	return (res);
}
