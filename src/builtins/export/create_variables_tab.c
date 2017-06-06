/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_variables_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:54:42 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/20 17:35:15 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "environment.h"
#include "ft_42sh.h"
#include "tools.h"
#include "builtins.h"

static size_t	get_tabsize(t_variable *lst_env, t_variable *lst_localvar,\
															size_t *indexsize)
{
	t_variable	*ptr;
	size_t		nb_index;

	nb_index = 0;
	ptr = lst_env;
	while (ptr)
	{
		if (*indexsize < ptr->length)
			*indexsize = ptr->length;
		ptr = ptr->next;
		++nb_index;
	}
	ptr = lst_localvar;
	while (ptr)
	{
		if (*indexsize < ptr->length)
			*indexsize = ptr->length + 1;
		ptr = ptr->next;
		++nb_index;
	}
	return (nb_index);
}

static int		is_key_duplicate(char ***tab, char *variable)
{
	size_t		len;
	char		*key;
	int			i;

	if (!(key = var_getkey(variable)))
		return (ERROR);
	len = ft_strlen(key);
	i = 0;
	while ((*tab)[i])
	{
		if (ft_strnequ((*tab)[i], key, len) && (*tab)[i][len] == '=')
		{
			(*tab)[i] = ft_strcpy((*tab)[i], "1");
			(*tab)[i] = ft_strcat((*tab)[i], variable);
			ft_strdel(&key);
			return (GOOD);
		}
		i++;
	}
	ft_strdel(&key);
	return (ERROR);
}

static int		copy_lst_to_tab(t_variable *lst_env, t_variable *lst_localvar,\
												char ***tab, size_t indexsize)
{
	t_variable	*ptr;
	int			i;

	i = 0;
	ptr = lst_env;
	while (ptr)
	{
		if (!((*tab)[i++] = tl_strndup(ptr->variable, indexsize)))
			return (ERROR);
		ptr = ptr->next;
	}
	ptr = lst_localvar;
	while (ptr)
	{
		if (!is_key_duplicate(tab, ptr->variable))
			if (!((*tab)[i++] = tl_strndup(ptr->variable, indexsize)))
				return (ERROR);
		ptr = ptr->next;
	}
	return (GOOD);
}

static void		alpha_sort_tab(char ***tab)
{
	int			i;
	char		*swap;
	char		*tmp1;
	char		*tmp2;

	i = 0;
	while ((*tab)[i + 1])
	{
		tmp1 = (*tab)[i][0] != '1' ? (*tab)[i] : (*tab)[i] + 1;
		tmp2 = (*tab)[i + 1][0] != '1' ? (*tab)[i + 1] : (*tab)[i + 1] + 1;
		if (ft_strcmp(tmp1, tmp2) > 0)
		{
			swap = (*tab)[i];
			(*tab)[i] = (*tab)[i + 1];
			(*tab)[i + 1] = swap;
			i = -1;
		}
		++i;
	}
}

char			**create_variables_tab(t_variable *lst_env,\
													t_variable *lst_localvar)
{
	char		**tab;
	size_t		nb_index;
	size_t		indexsize;

	tab = NULL;
	indexsize = 0;
	nb_index = 0;
	if (!(nb_index = get_tabsize(lst_env, lst_localvar, &indexsize)))
		return (NULL);
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (nb_index + 1))))
		return (NULL);
	copy_lst_to_tab(lst_env, lst_localvar, &tab, indexsize);
	alpha_sort_tab(&tab);
	return (tab);
}
