/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:50:15 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/20 17:35:27 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtins.h"
#include "tools.h"

static void	print_tab(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		if (*(tab[i]) != '1')
			ft_putendl(tab[i]);
		else
		{
			j = 1;
			while (tab[i][j] && tab[i][j] != '=')
				ft_putchar(tab[i][j++]);
			ft_putstr("='");
			ft_putstr(tab[i] + j + 1);
			ft_putstr("'\n");
		}
		i++;
	}
}

void		print_export(t_variable *lst_env, t_variable *lst_localvar)
{
	char	**tab;

	tab = NULL;
	if (!(tab = create_variables_tab(lst_env, lst_localvar)))
		return ;
	print_tab(tab);
	tl_freedoubletab(tab);
}
