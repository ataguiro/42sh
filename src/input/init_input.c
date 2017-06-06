/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <cjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:45:18 by cjacquem          #+#    #+#             */
/*   Updated: 2017/02/05 14:00:25 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void		init_input(void)
{
	cor()->x = 0;
	cor()->prompt_len = *prompt_len() + 1;
	if (*command())
		ft_strdel(command());
	*command() = strdup_input("");
}
