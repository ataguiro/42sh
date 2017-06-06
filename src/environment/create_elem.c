/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:58:25 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/08 15:58:26 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "libft.h"
#include "ft_42sh.h"
#include <stdlib.h>

/*
**		This function create a link at the end of the environment list.
**		The variable should already be the correct format ($KEY=$VALUE).
**		The length is then calculated to prevent useless realloc.
*/

static void	push_back(t_variable **lst_env, t_variable *new)
{
	t_variable	*elem;

	if (*lst_env)
	{
		elem = *lst_env;
		while (elem->next)
			elem = elem->next;
		elem->next = new;
	}
	else
		*lst_env = new;
}

int			create_elem(t_variable **lst_env, char *variable)
{
	t_variable	*new;

	if (!variable)
		return (ERROR);
	if (!(new = (t_variable*)malloc(sizeof(t_variable))))
		return (ERROR);
	if (!(new->variable = ft_strdup(variable)))
		return (ERROR);
	new->length = ft_strlen(variable);
	new->next = 0;
	push_back(lst_env, new);
	return (GOOD);
}
