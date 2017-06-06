/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_get_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:04:11 by yfuks             #+#    #+#             */
/*   Updated: 2017/01/13 17:50:44 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "execution.h"
#include "tools.h"
#include "expansion.h"

extern pid_t	g_heredoc_pid;

static char		*remove_tabs(char *s)
{
	int				i;
	char			*trim;

	i = 0;
	while (s[i] && s[i] == '\t')
		i++;
	trim = ft_strdup(&s[i]);
	return (trim);
}

static char		*check_line(t_shell *sh, t_redirections *r, char *line)
{
	char			*trim;

	if (r->type & CLOSE_REDIRECT)
		trim = remove_tabs(line);
	else
		trim = ft_strdup(line);
	trim = substitute(sh, trim);
	return (trim);
}

static t_list	*get_words(t_shell *sh, t_redirections *r)
{
	char			*line;
	char			*trim;
	t_list			*words;
	t_list			*cursor;

	cursor = 0;
	words = 0;
	signal(SIGINT, SIG_IGN);
	while (!(line = 0) && heredoc_prompt() && get_line(0, &line) == 1 &&
		ft_strcmp(line, r->dest) && (trim = check_line(sh, r, line)))
	{
		if (cursor == 0)
		{
			cursor = tl_lstnew(trim, ft_strlen(line));
			words = cursor;
		}
		else
		{
			cursor->next = tl_lstnew(trim, ft_strlen(line));
			cursor = cursor->next;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (words);
}

/*
**	this function add a command line to retrieve heredoc and put the words
**	into the cmd->heredocs
*/

void			get_heredoc(t_shell *sh, t_cmdwr *cmd, t_redirections *r)
{
	t_list		*heredocs_words;
	t_heredocs	*heredocs_list;

	heredocs_list = cmd->heredocs;
	heredocs_words = get_words(sh, r);
	if (heredocs_words)
	{
		while (heredocs_list && heredocs_list->next)
			heredocs_list = heredocs_list->next;
		if (!cmd->heredocs)
			cmd->heredocs = get_new_heredocs(heredocs_words);
		else
			heredocs_list->next = get_new_heredocs(heredocs_words);
	}
}
