/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <cjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:51:06 by cjacquem          #+#    #+#             */
/*   Updated: 2017/01/15 15:15:01 by cjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_read.h"
#include "libft.h"
#include "ft_42sh.h"
#include "tools.h"
#include <sys/select.h>

static int	launch_read(t_shell *sh, t_read tools, char **av, int i)
{
	char			*line;

	line = NULL;
	if (!read_input(tools, &line))
	{
		ft_strdel(&line);
		return (ERROR);
	}
	if (!(tools.option & OPTION_R))
		escape_line(&line);
	split_line_into_fields(sh, av + i, line);
	if (tools.option & OPTION_E)
		ft_putendl(line);
	ft_strdel(&line);
	return (GOOD);
}

static int	read_start_timer(t_shell *sh, t_read tools, char **av, int i)
{
	struct timeval	tv;
	fd_set			sock;
	int				ret;

	FD_ZERO(&sock);
	FD_SET(tools.fd, &sock);
	tv.tv_sec = tools.timeout;
	tv.tv_usec = 0;
	if ((ret = select(tools.fd + 1, &sock, NULL, NULL, &tv)) > 0)
	{
		return (launch_read(sh, tools, av, i));
	}
	else if (ret == 0)
	{
		ft_putstr(NONEWLINE);
		return (ERROR);
	}
	else
		return (ERROR);
}

int			builtin_read(t_shell *sh, int ac, char **av)
{
	int				i;
	t_read			tools;

	ft_bzero(&tools, sizeof(t_read));
	if ((i = read_get_options(av, &tools)) == -1)
		return (1);
	if (tools.option & OPTION_T)
	{
		if (!read_start_timer(sh, tools, av, i))
			return (1);
	}
	else
	{
		if (!launch_read(sh, tools, av, i))
			return (1);
	}
	(void)ac;
	return (0);
}
