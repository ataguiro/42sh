/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrcol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:27:21 by fhuang            #+#    #+#             */
/*   Updated: 2016/05/18 17:33:40 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrcol(char const *s, char *color)
{
	write(1, color, ft_strlen(color));
	write(1, s, ft_strlen(s));
	write(1, COLOR_RESET, ft_strlen(COLOR_RESET));
}
