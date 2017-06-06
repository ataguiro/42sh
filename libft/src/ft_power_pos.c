/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:05:16 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/03 19:17:04 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_power_pos(unsigned int n, unsigned int p)
{
	if (n == 0)
		return (0);
	else if (p == 0)
		return (1);
	else if (p == 1)
		return (n);
	else if (p % 2 == 0)
		return (ft_power_pos(n * n, p / 2));
	return (n * ft_power_pos(n * n, (p - 1) / 2));
}
