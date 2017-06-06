/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_get_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:07:29 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/01 16:17:27 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static char		*ft_purify(char *str, int size)
{
	int		i;
	int		j;
	char	*new;

	if (!str)
		return (NULL);
	new = ft_strnew(size);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\n')
		{
			new[j] = str[i];
			j++;
		}
		i++;
	}
	new[j] = 0;
	return (new);
}

char			*get_elem(int key)
{
	int				j;
	t_list			*list;

	j = 0;
	list = *get_full_list();
	*get_size() = ft_lstlen(list);
	(*pos() == -1000) ? *pos() = *get_size() : 0;
	if (key == CODE_UP)
		*pos() -= *pos() > 1 ? 1 : 0;
	else
		*pos() += *pos() < *get_size() ? 1 : 0;
	while (list && *pos() >= 0 && *pos() <= *get_size())
	{
		if (*pos() == j)
			return (ft_purify((char *)list->content, list->content_size));
		j++;
		list = list->next;
	}
	return (NULL);
}
