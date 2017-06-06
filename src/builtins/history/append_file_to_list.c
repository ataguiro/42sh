/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_file_to_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:08:27 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/18 18:23:36 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "tools.h"
#include "input.h"

#define HISTORY_FILE ".42sh_history"

int		history_append_file_to_list(char **av)
{
	int		fd;
	int		ret;
	char	*line;
	char	*path;

	path = NULL;
	fd = open(av && av[0] ? av[0] :\
		(path = tl_str3join(*get_home(), "/", HISTORY_FILE)), O_RDONLY);
	ft_strdel(&path);
	if (fd == -1)
		return (1);
	while ((ret = tl_get_next_line(fd, &line)) > 0)
	{
		ft_lstaddend(get_full_list(), ft_lstnew(line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (ret == -1 || close(fd) == -1)
		return (1);
	return (0);
}
