/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/03 22:08:09 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/07 14:52:04 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	update_line_lfo(char **line, char **lfo)
{
	if (*lfo)
	{
		*line = ft_strdup(*lfo);
		free(*lfo);
		*lfo = NULL;
	}
	else
		*line = (char*)ft_strnew(1);
	if (*line == NULL)
		return (-1);
	return (0);
}

int			read_stdin(char **line)
{
	int				ret;
	static char		*lfo = NULL;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];

	if (BUFF_SIZE <= 0 || update_line_lfo(line, &lfo) == -1)
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	while ((ft_strchr(*line, '\n') == 0) && (ret = read(0, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		if (!(*line = ft_strjoin_free(*line, buf)))
			return (-1);
	}
	tmp = ft_strstr(*line, "\n");
	if (tmp)
	{
		lfo = ft_strdup(tmp + 1);
		ft_bzero(tmp, ft_strlen(tmp));
	}
	return (ret ? 1 : 0);
}
