/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:16:36 by fhuang            #+#    #+#             */
/*   Updated: 2016/11/30 12:35:32 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"

int		builtin_unset(t_shell *sh, int ac, char **av)
{
	if (ac == 1)
	{
		ft_putendl_fd("unset: not enough arguments.", 2);
		return (1);
	}
	while (--ac >= 1)
		sh_unsetenv(&sh->lst_localvar, av[ac]);
	return (0);
}
