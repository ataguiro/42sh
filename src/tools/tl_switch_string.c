/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_switch_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:53:17 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/19 17:43:45 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*tl_switch_string(char *line, int i, char *plus, char *minus)
{
	char	*tmp;

	if (!minus || !line)
		return (NULL);
	if (!(tmp = ft_memalloc(ft_strlen(line) + (!plus ? 0 : ft_strlen(plus) -\
		ft_strlen(minus) + 1))))
		return (NULL);
	tmp = ft_strncat(tmp, line, i);
	if (plus)
		tmp = ft_strcat(tmp, plus);
	tmp = ft_strcat(tmp, line + i + ft_strlen(minus));
	ft_strdel(&line);
	return (tmp);
}
