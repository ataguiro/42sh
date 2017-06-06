/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_lsttotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoac <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:03:39 by tpoac             #+#    #+#             */
/*   Updated: 2017/01/26 18:16:21 by tpoac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static size_t	tl_lstsize(t_list *list)
{
	t_list		*tmp;
	size_t		i;

	tmp = list;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char			**tl_lsttotab(t_list *lst_tab)
{
	t_list		*tmp;
	size_t		i;
	char		**tab;

	if (!lst_tab)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (tl_lstsize(lst_tab) + 1))))
		return (NULL);
	i = 0;
	tmp = lst_tab;
	while (tmp)
	{
		tab[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	tab[i] = NULL;
	return (tab);
}
