/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:52:07 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/25 12:18:30 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "history.h"
#include "tools.h"

static char	*tab_to_str(char **tab)
{
	char	*tmp;
	char	*ret;
	int		i;

	if (!tab)
		return (NULL);
	i = 0;
	ret = NULL;
	tmp = NULL;
	while (tab[i])
	{
		if (!ret)
			ret = ft_strdup(tab[i]);
		else
		{
			tmp = tl_str3join(ret, " ", tab[i]);
			ft_strdel(&ret);
			ret = tmp;
		}
		if (!ret)
			return (NULL);
		i++;
	}
	return (ret);
}

int			history_option_s(char **av)
{
	char	*str;

	if (!av || !av[0])
		return (0);
	str = NULL;
	delete_last_entry();
	if (!(str = tab_to_str(av)))
		return (1);
	save_command_line(str);
	ft_strdel(&str);
	return (0);
}
