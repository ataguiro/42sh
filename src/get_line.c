/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:48:17 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/16 13:33:13 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_42sh.h"
#include "libft.h"
#include "tools.h"
#include <unistd.h>

/*
**			This function receive the data wrote in the prompt (line).
*/

static int	clear_buf(char **buf, int ret)
{
	if (!*buf)
		return (ret);
	ft_strclr(*buf);
	ft_strdel(buf);
	return (ret);
}

static int	save_line(char **line, char **buf, size_t size)
{
	if (*line)
	{
		if (!(*line = tl_strrealloc(*line, size)))
			return (ERROR);
		ft_strncat(*line, *buf, size);
	}
	else if (!(*line = tl_strndup(*buf, size)))
		return (ERROR);
	return (clear_buf(buf, GOOD));
}

static int	push_line(char **tmp, char **line, char **buf, size_t size)
{
	if (!(*tmp = ft_strchr(*buf, '\n')))
		return (save_line(line, buf, size) - 1);
	else
	{
		size = (size_t)(*tmp - *buf);
		return (save_line(line, buf, size));
	}
	return (GOOD);
}

int			get_line(int fd, char **line)
{
	static char	*tmp = NULL;
	char		*buf;
	int			ret;

	if ((fd < 0 || 255 < fd) || BUFF_SIZE <= 0 || !line)
		return (ERROR);
	while (tmp)
		if (!(buf = ft_strdup(tmp + 1)))
			return (ERROR);
		else if (push_line(&tmp, line, &buf, ft_strlen(buf)))
			return (GOOD);
	if (!(buf = ft_strnew(BUFF_SIZE + 1)))
		return (ERROR);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (clear_buf(&buf, -1));
		if (push_line(&tmp, line, &buf, ret))
			return (GOOD);
		else
			buf = ft_strnew(BUFF_SIZE + 1);
	}
	clear_buf(&buf, 0);
	return (*line && ft_strlen(*line) > 0 && ret != -1 ? GOOD : 0);
}
