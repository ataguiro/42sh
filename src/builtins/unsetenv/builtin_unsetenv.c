/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <cjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:56:25 by cjacquem          #+#    #+#             */
/*   Updated: 2017/01/15 15:43:22 by cjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"
#include "environment.h"

int			builtin_unsetenv(t_shell *sh, int ac, char **av)
{
	if (ac == 1)
	{
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
		return (1);
	}
	while (ac-- >= 1)
		sh_unsetenv(&sh->lst_env, av[ac]);
	return (0);
}
