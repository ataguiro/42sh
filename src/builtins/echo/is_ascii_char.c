/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ascii_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:20:25 by fhuang            #+#    #+#             */
/*   Updated: 2016/11/11 12:42:17 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_42sh.h"
#include "builtin_echo.h"

/*
**	This function prints the escaped characters when
**	ascii octal or/and hexadecimal codes are in the string.
*/

static int	echo_is_xdigit(int c)
{
	return (ft_isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

int			echo_is_ascii_char(char *str, int *i)
{
	int		ascii;
	int		base;

	ascii = 0;
	if (*str == 'x')
	{
		if (!ft_isdigit(*(str + 1)) ||\
			(*(str + 2) && !echo_is_xdigit(*(str + 2))))
			return (ERROR);
		base = 16;
	}
	else if (*str == '0')
		base = 8;
	else
		return (ERROR);
	*i += echo_atoi_base(str + 1, &ascii, base, base == 16 ? 2 : 3);
	ft_putchar(ascii);
	return (GOOD);
}
