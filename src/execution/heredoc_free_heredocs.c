/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_free_heredocs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:31:44 by yfuks             #+#    #+#             */
/*   Updated: 2016/12/01 21:15:07 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <unistd.h>

void		free_heredocs(t_cmdwr *cmd)
{
	t_heredocs		*cursor;
	t_heredocs		*tofree;
	t_list			*list_cursor;
	t_list			*list_tofree;

	cursor = cmd->heredocs;
	while (cursor)
	{
		list_cursor = cursor->words;
		while (list_cursor)
		{
			list_tofree = list_cursor;
			list_cursor = list_cursor->next;
			free(list_tofree->content);
			list_tofree->content = NULL;
			free(list_tofree);
			list_tofree = NULL;
		}
		tofree = cursor;
		cursor = cursor->next;
		free(tofree);
		tofree = NULL;
	}
	cmd->heredocs = NULL;
}
