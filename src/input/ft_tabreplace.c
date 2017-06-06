/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:59:40 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/23 16:58:55 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "tools.h"

int		ft_tabreplace(char ***tab, char *str, char *by)
{
	size_t	i;
	char	*cleaner_str;
	char	**cleaner;

	i = 0;
	cleaner_str = ft_strjoin(str, "=");
	while ((*tab)[i])
	{
		if (!ft_strncmp((*tab)[i], cleaner_str, ft_strlen(cleaner_str)))
		{
			if (by)
				break ;
			else
				(*tab)[i][0] = 0;
		}
		i++;
	}
	ft_strdel(&cleaner_str);
	by && (*tab)[i] ? free((*tab)[i]) : 0;
	(by) ? (*tab)[i] = strdup_input(by) : 0;
	cleaner = *tab;
	*tab = ft_tabdup(*tab);
	tl_freedoubletab(cleaner);
	cleaner = NULL;
	return (i);
}

char	*newclean(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = ft_strnew(ft_strlen(str));
	while (str[i])
	{
		if (ft_isprint(str[i]))
		{
			new[j] = str[i];
			j++;
		}
		i++;
	}
	new[j] = 0;
	return (new);
}
