/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:53:44 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/07 12:44:34 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(const char *str, int base)
{
	int			i;
	int			res;
	int			negatif;

	res = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		++i;
	negatif = str[i] == '-' ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] && ft_isdigit(str[i]))
	{
		res *= base;
		res += negatif * (str[i] - '0');
		++i;
	}
	return (res);
}
