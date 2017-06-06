/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:48:02 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/15 15:05:24 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_read.h"
#include "libft.h"
#include "ft_42sh.h"
#include "tools.h"
#include <fcntl.h>

int			read_option_u(t_read *tools, char **av, int *i, int *j)
{
	if (av[*i][*j] == 0)
	{
		(*i)++;
		*j = 0;
	}
	if (av[*i] && av[*i][*j])
	{
		if (tl_isstrdigit(av[*i] + *j))
		{
			tools->option |= OPTION_U;
			tools->fd = ft_atoi(av[*i] + *j);
			return (GOOD);
		}
		else
			return (read_option_error(av[*i] + *j,\
				"invalid file descriptor specification"));
	}
	read_option_error("-u", "option requires an argument");
	return (ERROR);
}
