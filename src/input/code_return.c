/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_return.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:32:26 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/25 14:33:14 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	code_return(int *key)
{
	char	*tmp;
	int		i;

	i = 0;
	*pos() = -1000;
	*search_mode() = 0;
	*key = CODE_END;
	default_mode();
	if (*found())
	{
		tmp = *found();
		tmp = &tmp[cor()->x];
		while (tmp[i])
		{
			manage_command(tmp[i]);
			i++;
		}
		ft_strdel(found());
	}
	default_mode();
}
