/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:37:26 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/18 20:05:51 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "tools.h"
#include "history.h"
#include "input.h"

static void	set_new_histo_list(void)
{
	t_list	*ptr;

	ptr = *get_full_list();
	while (ptr && ptr->next)
		ptr = ptr->next;
	*get_new_list() = ptr;
}

void		init_history_list(void)
{
	int		fd;
	char	*line;
	char	*path;

	line = NULL;
	path = ft_strjoin(*get_home(), "/.42sh_history");
	fd = open(path, O_RDONLY);
	ft_strdel(&path);
	if (fd == -1)
		return ;
	while (tl_get_next_line(fd, &line) > 0)
	{
		if (!tl_isstrempty(line))
			ft_lstaddend(get_full_list(), ft_lstnew(line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	ft_strdel(&line);
	set_new_histo_list();
}
