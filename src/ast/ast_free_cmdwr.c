/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_free_cmdwr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:34:49 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/01 12:24:58 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "libft.h"
#include "tools.h"

void	ast_free_list(void *memo, size_t size)
{
	(void)size;
	free(memo);
	memo = NULL;
}

void	ast_free_cmdwr(t_cmdwr **cmd)
{
	t_redirections	*ptr;
	t_redirections	*tmp;

	if (!*cmd)
		return ;
	if ((*cmd)->command)
		tl_freedoubletab((*cmd)->command);
	if ((*cmd)->redirs)
	{
		ptr = (*cmd)->redirs;
		tmp = NULL;
		while (ptr)
		{
			tmp = ptr;
			ptr = ptr->next;
			if (tmp->dest)
				ft_strdel(&tmp->dest);
			ft_memdel((void*)&tmp);
		}
	}
	free(*cmd);
	*cmd = NULL;
}
