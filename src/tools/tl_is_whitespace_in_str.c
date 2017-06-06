/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_is_whitespace_in_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:22:34 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/20 17:23:08 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int		tl_is_whitespace_in_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (tl_iswhitespace(str[i]))
			return (1);
		i++;
	}
	return (0);
}
