/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:34:37 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/15 14:37:42 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_read.h"
#include "libft.h"
#include "ft_42sh.h"

int			read_option_p(t_read *tools, char **av, int *i, int *j)
{
	if (av[*i][*j] == 0)
	{
		(*i)++;
		*j = 0;
	}
	if (av[*i] && av[*i][*j])
	{
		tools->option |= OPTION_P;
		tools->prompt = ft_strdup(av[*i] + *j);
		return (GOOD);
	}
	read_option_error("-p", "option requires an argument");
	return (ERROR);
}
