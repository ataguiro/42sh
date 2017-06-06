/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_ctrl_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 12:17:58 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/18 15:29:14 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	code_ctrl_d(void)
{
	if (!(*command() && (*command())[0]))
	{
		default_mode();
		ft_putchar('\n');
	}
	if (*command() && cor()->x < cor()->len)
	{
		move_right(1);
		cor()->x++;
		stremove();
	}
	if (*dquote() % 2 || *quote() % 2)
	{
		reset_quotes();
		init_input();
	}
}
