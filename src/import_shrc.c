/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_shrc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:41:29 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/12 18:48:28 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include "ft_42sh.h"
#include "libft.h"
#include "environment.h"
#include "tools.h"

#define RC_FILENAME ".42shrc"

static int	execute_line(t_shell *sh, char **line)
{
	t_list	*lst_commands;

	lst_commands = NULL;
	if (!*line)
		return (ERROR);
	lexer_parser(line, &lst_commands);
	loop_through_commands(sh, lst_commands);
	tl_lstdelast(&lst_commands);
	return (GOOD);
}

int			import_shrc(t_shell *sh)
{
	char	*line;
	char	*rc_path;
	int		fd;

	rc_path = NULL;
	if (!(rc_path = getpwuid(getuid())->pw_dir))
		return (ERROR);
	if (!(rc_path = tl_str3join(rc_path, "/", RC_FILENAME)))
		return (ERROR);
	fd = open(rc_path, O_RDONLY);
	ft_strdel(&rc_path);
	if (fd == -1)
		return (ERROR);
	line = NULL;
	while (tl_get_next_line(fd, &line) > 0)
	{
		execute_line(sh, &line);
		ft_strdel(&line);
	}
	return (close(fd) == -1 ? ERROR : GOOD);
}
