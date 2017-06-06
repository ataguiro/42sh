/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_shift_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:33:03 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/08 12:33:10 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	code_shift_down(void)
{
	size_t	t;

	t = cor()->x + termsize()->col;
	while (cor()->x <= cor()->len && cor()->x <= t)
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
	move_left(1);
	(cor()->x)--;
}
