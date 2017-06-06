/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:58:36 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/08 15:59:44 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "libft.h"
#include "ft_42sh.h"
#include "tools.h"

/*
**		This function searches the environment list to find the
**		environment variable key, and remove the corresponding
**		environment variable.
**
**		Return GOOD on success, and ERROR if the key was not found.
*/

static int	delete_elem(t_variable **lst, t_variable **elem, t_variable **prev)
{
	if (*prev)
		(*prev)->next = (*elem)->next;
	else
		*lst = (*elem)->next;
	ft_strdel(&(*elem)->variable);
	ft_memdel((void*)&(*elem));
	return (GOOD);
}

int			sh_unsetenv(t_variable **lst_env, char *key)
{
	t_variable	*elem;
	t_variable	*prev;
	char		*tmp_key;
	size_t		len_key;

	elem = *lst_env;
	prev = NULL;
	while (elem && key)
	{
		len_key = (size_t)(ft_strchr(elem->variable, '=') - elem->variable);
		if ((tmp_key = tl_strndup(elem->variable, len_key)))
		{
			if (ft_strequ(key, tmp_key))
			{
				ft_strdel(&tmp_key);
				return (delete_elem(lst_env, &elem, &prev));
			}
			ft_strdel(&tmp_key);
		}
		prev = elem;
		elem = elem->next;
	}
	return (ERROR);
}
