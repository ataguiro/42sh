/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_delim_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 21:54:03 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/03 14:18:37 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	is_delim_char(char *str, int i)
{
	if (!str)
		return (0);
	if (tl_iswhitespace(str[i]) ||\
		(str[i] == ';' && (i == 0 || str[i - 1] != '\\')) ||\
		(str[i] == '&' && ((i == 1 && str[i - 1] == '&') || \
		(i > 1 && str[i - 1] == '&' && str[i - 2] != '\\'))) ||\
		(str[i] == '|' && ((i == 1 && str[i - 1] == '|') ||\
		(i > 1 && str[i - 1] == '|' && str[i - 2] != '\\'))))
		return (1);
	if (ft_isprint(str[i]) || (\
		str[i] == '\x9') || str[i] == '\x4' || str[i] == '\x12' || \
		str[i] == '\x7f' || str[i] == '\xa' || str[i] == '\x1b' || \
		str[i] == '\x5b' || str[i] == '\x41' || str[i] == '\x42' || \
		str[i] == '\x43' || str[i] == '\x44' || str[i] == '\x48' || \
		str[i] == '\x46' || str[i] == '\x31' || str[i] == '\x32' || \
		str[i] == '\x3b' || str[i] == '\x42' || str[i] == '\x41' || \
		str[i] == '\x18' || str[i] == '\x15' || str[i] == '\x17' || \
		str[i] == '\x0c' || str[i] == '\x01' || str[i] == '\x05')
		return (1);
	return (0);
}
