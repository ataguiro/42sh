/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 22:25:59 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/25 00:32:56 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include "input.h"

static void	change_command(char **save_end, char *cmd_before, char *to_add)
{
	*save_end = NULL;
	if (*command() && (*command())[0])
	{
		*save_end = ft_strdup(*command() + cor()->x);
		*command() = tl_switch_string(cmd_before, cor()->x, to_add, "");
	}
	else
	{
		ft_strdel(command());
		*command() = ft_strdup(to_add);
	}
}

static void	command_to_cursor(char *cmd_before, char *to_add)
{
	char	*save_end;
	char	*tmp;

	save_end = NULL;
	tmp = NULL;
	if (ft_lstlen(*get_list_completion()) == 1 && tl_is_a_directory(to_add))
	{
		tmp = ft_strjoin(to_add, "/");
		to_add = tmp;
		clear_completion();
	}
	change_command(&save_end, cmd_before, to_add);
	cor()->len = ft_strlen(*command());
	cor()->x = cor()->len - (save_end ? ft_strlen(save_end) : 0);
	default_mode();
	ft_putstr(to_add);
	if (save_end)
	{
		ft_putstr(save_end);
		move_left(ft_strlen(save_end));
		ft_strdel(&save_end);
	}
	raw_mode();
	tmp ? ft_strdel(&tmp) : 0;
}

static void	command_back_to_what_it_was(char **save, int pos)
{
	if (!*save)
		return ;
	code_end();
	while (cor()->x)
		stremove();
	cor()->len = 0;
	ft_strdel(command());
	*command() = *save;
	default_mode();
	ft_putstr(*save);
	raw_mode();
	cor()->x = ft_strlen(*save);
	cor()->len = cor()->x;
	move_left(cor()->x - pos);
	cor()->x = pos;
}

void		display_command(char **save, int pos)
{
	t_list	*cursor;

	if ((cursor = *get_cursor_completion()) && cursor->content)
	{
		command_to_cursor(*command(), cursor->content);
		ft_strdel(&(*save));
	}
	else
		command_back_to_what_it_was(save, pos);
}
