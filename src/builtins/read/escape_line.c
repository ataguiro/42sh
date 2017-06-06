/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:06:20 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/20 17:37:16 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	shift_string(char *str)
{
	int		i;

	i = 0;
	while (str[i + 1])
	{
		str[i] = str[i + 1];
		i++;
	}
	ft_strclr(str + i);
}

void		escape_line(char **line)
{
	int		i;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '\\')
		{
			if ((*line)[i + 1] == '\\')
				shift_string((*line) + i);
			else
				i++;
		}
		i++;
	}
}
