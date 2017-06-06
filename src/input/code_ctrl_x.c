/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_ctrl_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:29:12 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/08 12:29:47 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	code_ctrl_x(void)
{
	ft_strdel(copied());
	*copied() = strdup_input(&(*command())[cor()->x]);
	fill_space(ft_strlen(*copied()));
	(*command())[cor()->x] = 0;
}
