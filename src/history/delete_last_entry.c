/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_last_entry.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:13:38 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/20 13:20:32 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "history.h"

void	delete_last_entry(void)
{
	t_list	*lst;
	t_list	*prev;

	if (!(lst = *get_full_list()))
		return ;
	prev = NULL;
	while (lst->next)
	{
		prev = lst;
		lst = lst->next;
	}
	if (prev)
		prev->next = lst->next;
	else
		*get_full_list() = lst->next;
	if (lst->content)
		free(lst->content);
	lst->content = NULL;
	lst->content_size = 0;
	free(lst);
	lst = NULL;
}
