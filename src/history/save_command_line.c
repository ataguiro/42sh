/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_command_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <cjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:43:41 by cjacquem          #+#    #+#             */
/*   Updated: 2017/01/18 21:28:33 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"
#include "history.h"
#include "tools.h"

static void	add_command_in_list(char *command_line)
{
	t_list	*ptr;
	char	*tmp;

	ptr = *get_full_list();
	while (ptr && ptr->next)
		ptr = ptr->next;
	tmp = ft_strtrim(command_line);
	if (ptr && ptr->content)
		if (ft_strequ(ptr->content, tmp))
		{
			ft_strdel(&tmp);
			return ;
		}
	ptr->next = ft_lstnew(command_line, ft_strlen(command_line) + 1);
	ft_strdel(&tmp);
}

int			save_command_line(char *command_line)
{
	if (!command_line || tl_isstrempty(command_line))
		return (GOOD);
	add_command_in_list(command_line);
	return (GOOD);
}
