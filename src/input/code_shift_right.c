/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_shift_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:33:30 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/08 12:33:40 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	code_shift_right(void)
{
	if (cor()->x < cor()->len)
	{
		if (!((cor()->x + cor()->prompt_len) % termsize()->col))
		{
			move_down(1);
			move_left(termsize()->col - 1);
			move_right(1);
		}
		else
			move_right(1);
		(cor()->x)++;
	}
	while (!(!ft_isspace((*command())[cor()->x - 1]) &&
				ft_isspace((*command())[cor()->x])) && cor()->x < cor()->len)
	{
		if (!((cor()->x + cor()->prompt_len) % termsize()->col))
		{
			move_down(1);
			move_left(termsize()->col - 1);
			move_right(1);
		}
		else
			move_right(1);
		(cor()->x)++;
	}
}
