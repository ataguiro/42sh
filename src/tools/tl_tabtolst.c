/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_tabtolst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoac <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:53:48 by tpoac             #+#    #+#             */
/*   Updated: 2017/01/25 18:41:53 by tpoac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

t_list			*tl_tabtolst(char **tab)
{
	int			i;
	t_list		*top;
	t_list		*new;

	if (!tab || !*tab)
		return (NULL);
	i = 0;
	top = NULL;
	new = NULL;
	while (tab[i])
	{
		new = ft_lstnew(tab[i], ft_strlen(tab[i]) + 1);
		if (top)
			tl_lstaddend(&top, new);
		else
			top = new;
		i++;
	}
	return (top);
}
