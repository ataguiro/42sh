/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:01:58 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/23 16:19:11 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	remove_display(char *to_add)
{
	size_t	diff;
	size_t	i;

	i = 0;
	diff = cor()->len - cor()->x;
	while (i < diff + 10)
	{
		ft_putchar(' ');
		i++;
	}
	move_left(diff + 10);
	ft_putstr(to_add);
	move_left(ft_strlen(to_add));
}
