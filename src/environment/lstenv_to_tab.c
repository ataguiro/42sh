/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstenv_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:53:59 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/12 19:09:17 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "libft.h"

char			**lstenv_to_tab(t_variable *lst_env)
{
	char	**tab;
	int		i;

	if (!(tab = (char**)ft_memalloc(sizeof(char*) *\
		(lstvariable_len(lst_env) + 1))))
		return (NULL);
	i = 0;
	while (lst_env)
	{
		tab[i++] = lst_env->variable;
		lst_env = lst_env->next;
	}
	tab[i] = NULL;
	return (tab);
}
