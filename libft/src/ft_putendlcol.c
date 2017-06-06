/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendlcol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:30:11 by fhuang            #+#    #+#             */
/*   Updated: 2016/05/18 17:33:54 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendlcol(char const *s, char *color)
{
	write(1, color, ft_strlen(color));
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	write(1, COLOR_RESET, ft_strlen(COLOR_RESET));
}
