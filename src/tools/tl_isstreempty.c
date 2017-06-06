/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_isstreempty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:26:40 by fhuang            #+#    #+#             */
/*   Updated: 2016/11/25 15:26:55 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	tl_isstrempty(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!tl_iswhitespace(str[i]))
			return (0);
		i++;
	}
	return (1);
}
