/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:41:46 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/17 12:27:17 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include "builtin_read.h"
#include "libft.h"
#include "ft_42sh.h"
#include "tools.h"
#include "input.h"
#include "tools.h"

static int	read_fd_error(int fd)
{
	ft_putstr_fd("42sh : read: ", 2);
	ft_putnbr_fd(fd, 2);
	ft_putstr_fd(": invalid file descriptor: Bad file descriptor\n", 2);
	return (ERROR);
}

static int	one_line_down(t_read tools, char **line, char c)
{
	move_left(ft_strlen(*line));
	move_down(1);
	if (tools.option & OPTION_D && c == '\n')
		*line = tl_strmerge(*line, " ");
	return (GOOD);
}

static int	read_with_termcaps(t_read tools, char **line, int fd)
{
	char	c[2];
	int		ret;

	while (1)
	{
		ft_bzero(&c, 2);
		if ((ret = read(fd, &c, 1)) == -1)
			return (read_fd_error(tools.fd));
		if (c[0] != '\n' && (*line = tl_strmerge(*line, c)))
			if (!(tools.option & OPTION_S))
				ft_putstr(c);
		if (tools.option & OPTION_N && ft_strlen(*line) == tools.nchars)
			return (one_line_down(tools, line, c[0]));
		else if (tools.option & OPTION_D)
		{
			if ((c[0] == tools.delim || c[0] == '\n') && \
				one_line_down(tools, line, c[0]))
				if (c[0] == tools.delim)
					return (GOOD);
		}
		else if (c[0] == '\n' || c[0] == 4)
			return (GOOD);
	}
}

int			read_input(t_read tools, char **line)
{
	int		fd;
	int		ret;

	fd = tools.option & OPTION_U ? tools.fd : 0;
	ret = 0;
	signal(SIGINT, SIG_IGN);
	if (tools.option & OPTION_P)
	{
		ft_putstr(tools.prompt);
		ft_strdel(&tools.prompt);
	}
	if (!(tools.option & OPTION_D) &&\
		!(tools.option & OPTION_S) && !(tools.option & OPTION_N))
	{
		if ((ret = get_line(fd, line)) == -1)
			return (read_fd_error(tools.fd));
		raw_mode();
		return (ret == 0 ? ERROR : GOOD);
	}
	else
	{
		raw_mode();
		*line = ft_strnew(0);
		return (read_with_termcaps(tools, line, fd));
	}
}
