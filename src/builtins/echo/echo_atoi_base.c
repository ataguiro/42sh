/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_atoi_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:15:36 by fhuang            #+#    #+#             */
/*   Updated: 2016/11/11 12:42:39 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"

static int	echo_is_octal(int c)
{
	return (c >= '0' && c < '8');
}

static int	echo_get_atoi_addition(int c)
{
	const char	pattern[] = "0123456789abcdef";
	int			i;

	i = 0;
	c = ft_tolower(c);
	while (pattern[i])
	{
		if (c == pattern[i])
			return (i);
		i++;
	}
	return (0);
}

int			echo_atoi_base(const char *str, int *ret, int base, int nb_char)
{
	const char	*ptr;
	int			tmp;

	ptr = str;
	tmp = nb_char;
	while (tmp > 0 && *ptr == '0')
	{
		ptr++;
		tmp--;
	}
	while (tmp > 0 && *ptr)
	{
		if (base == 8 && !echo_is_octal(*ptr))
			break ;
		*ret *= base;
		*ret += echo_get_atoi_addition(*ptr);
		ptr++;
		tmp--;
	}
	return (nb_char - tmp);
}
