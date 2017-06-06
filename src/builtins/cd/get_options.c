/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:40:08 by fhuang            #+#    #+#             */
/*   Updated: 2016/11/28 18:35:13 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"

/*
**	This functions retrieves the options given to the cd built-in.
**	Synospsis :
**		cd [-L | -P] [directory]
*/

static int	is_option(char *str, _Bool *follow_sl)
{
	int		i;

	if (ft_strequ(str, "--"))
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] == 'P')
			*follow_sl = 0;
		else if (str[i] != 'P' && str[i] != 'L')
			return (-1);
		i++;
	}
	return (1);
}

_Bool		get_options(char **av, int *i)
{
	int		ret;
	_Bool	follow_sl;

	follow_sl = 1;
	ret = 0;
	while (av[*i] && *av[*i] == '-' && av[*i][1])
	{
		if ((ret = is_option(av[*i], &follow_sl)) <= 0)
		{
			if (ret == 0)
				(*i)++;
			break ;
		}
		(*i)++;
	}
	return (follow_sl);
}
