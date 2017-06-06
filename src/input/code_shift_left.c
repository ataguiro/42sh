/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_shift_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:33:19 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/08 12:33:22 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	code_shift_left(void)
{
	if (cor()->x > 0)
	{
		(cor()->x)--;
		move_left(1);
	}
	while (!(!ft_isspace((*command())[cor()->x - 1]) &&
				ft_isspace((*command())[cor()->x])) && cor()->x > 0)
	{
		move_left(1);
		(cor()->x)--;
	}
}
