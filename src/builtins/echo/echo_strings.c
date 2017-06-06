/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:20:23 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/19 16:07:41 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_echo.h"
#include "ft_42sh.h"
#include "libft.h"
#include <unistd.h>

#ifndef NB_ESC_CHAR
# define NB_ESC_CHAR 9
#endif

/*
**	This function outputs the given string.
**	If -e is on, escaped characters are treated.
*/

static const t_escaped_char	g_escaped_char[NB_ESC_CHAR] = {
	{'a', "\a"},
	{'b', "\b"},
	{'e', "\e"},
	{'f', "\f"},
	{'n', "\n"},
	{'r', "\r"},
	{'t', "\t"},
	{'v', "\v"},
	{'\\', "\\"}
};

static int	echo_escaped_char(char c)
{
	int		i;

	i = 0;
	while (i < NB_ESC_CHAR)
	{
		if (c == g_escaped_char[i].c)
		{
			if (write(1, g_escaped_char[i].escaped_char, 1) == -1)
				return (ERROR);
			return (GOOD);
		}
		i++;
	}
	return (ERROR);
}

int			echo_strings(_Bool option[2], char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (option[1] && str[i] == '\\')
		{
			if (!echo_escaped_char(str[++i]))
				if (!echo_is_ascii_char(str + i, &i))
					ft_putchar(str[--i]);
		}
		else if (str + i)
		{
			if (write(1, str + i, 1) == -1)
				return (ERROR);
		}
		i++;
	}
	return (GOOD);
}
