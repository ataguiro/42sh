/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alias.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:49:44 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/20 17:37:33 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "builtins.h"
#include "tools.h"
#include "libft.h"

static void		sort_alpha_tab(char ***tab)
{
	int			i;
	char		*swap;

	i = 0;
	while ((*tab)[i + 1])
	{
		if (ft_strcmp((*tab)[i], (*tab)[i + 1]) > 0)
		{
			swap = (*tab)[i];
			(*tab)[i] = (*tab)[i + 1];
			(*tab)[i + 1] = swap;
			i = -1;
		}
		++i;
	}
}

static size_t	biggest_indext(t_variable *lst_alias)
{
	t_variable	*ptr;
	size_t		index_size;

	index_size = 0;
	ptr = lst_alias;
	while (ptr)
	{
		if (ptr->length > index_size)
			index_size = ptr->length;
		ptr = ptr->next;
	}
	return (index_size);
}

static char		**get_alias_table(t_variable *lst_alias)
{
	t_variable	*ptr;
	size_t		index_size;
	char		**tab;
	int			i;

	if (!(tab = (char**)ft_memalloc(sizeof(char*) *\
		(lstvariable_len(lst_alias) + 1))))
		return (NULL);
	ptr = lst_alias;
	index_size = biggest_indext(lst_alias);
	i = 0;
	while (ptr)
	{
		tab[i] = tl_strndup(ptr->variable, index_size);
		ptr = ptr->next;
		i++;
	}
	tab[i] = NULL;
	sort_alpha_tab(&tab);
	return (tab);
}

static void		print_tab(char **tab)
{
	int			i;
	int			j;

	i = 0;
	while (tab[i])
	{
		ft_putstr("alias ");
		j = 0;
		while (tab[i][j] && tab[i][j] != '=')
			ft_putchar(tab[i][j++]);
		ft_putstr("='");
		ft_putstr(tab[i] + j + 1);
		ft_putstr("'\n");
		++i;
	}
}

void			print_alias(t_variable *lst_alias)
{
	char		**tab;

	if (!lst_alias)
		return ;
	if (!(tab = get_alias_table(lst_alias)))
		return ;
	print_tab(tab);
	tl_freedoubletab(tab);
}
