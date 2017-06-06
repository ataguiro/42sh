/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overwrite_history_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 21:16:34 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/18 21:41:04 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_42sh.h"
#include "history.h"
#include "libft.h"
#include "tools.h"

int		overwrite_history_file(t_list *lst_history)
{
	int			fd;
	char		*path;

	if (lst_history && (path = *get_home()))
	{
		path = tl_str3join(path, "/", HISTORY);
		fd = open(path, O_WRONLY | O_TRUNC | O_CREAT,\
						S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		ft_strdel(&path);
		if (fd == -1)
			return (1);
		while (lst_history)
		{
			if (lst_history->content)
				ft_putendl_fd(lst_history->content, fd);
			lst_history = lst_history->next;
		}
		if (close(fd) == -1)
			return (1);
	}
	return (0);
}
