/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:50:47 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/15 14:37:59 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_read.h"
#include "libft.h"
#include "ft_42sh.h"

int	read_option_d(t_read *tools, char **av, int *i, int *j)
{
	while (av[*i])
	{
		while (av[*i][*j])
		{
			tools->option |= OPTION_D;
			tools->delim = av[*i][*j];
			return (GOOD);
		}
		*j = 0;
		(*i)++;
	}
	ft_putendl_fd("42sh: read: -d: option requires an argument", 2);
	return (ERROR);
}
