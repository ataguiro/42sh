/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_ctrl_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 11:55:23 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/13 11:55:24 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	code_ctrl_l(void)
{
	ft_putstr("\033[H\033[J");
	prompt();
	*command() && (*command())[0] ? ft_putstr(*command()) : 0;
	move_left(cor()->len - cor()->x);
}
