/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_substitution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoac <tpoac@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:55:25 by tpoac             #+#    #+#             */
/*   Updated: 2017/02/05 16:42:38 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

t_list			*glob_substitution(t_list **lst_tab)
{
	t_list		*tmp;
	t_list		*glob;
	t_list		*result;

	if (!lst_tab || !*lst_tab)
		return (0);
	tmp = *lst_tab;
	glob = NULL;
	result = NULL;
	while (tmp)
	{
		if (!(glob = ft_glob(tmp->content)))
			glob = ft_lstnew(tmp->content, ft_strlen(tmp->content) + 1);
		if (result)
			tl_lstaddend(&result, glob);
		else
			result = glob;
		free(tmp->content);
		tmp = tmp->next;
	}
	return (result);
}
