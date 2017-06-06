/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_option_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:44:08 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/11 12:37:01 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include "libft.h"

static	const	char	g_options_i[][21] = {
	{"-"},
	{"-i"},
	{"--ignore-environment"},
	{0}
};

int		env_is_option_i(char *str)
{
	int		i;

	i = 0;
	while (g_options_i[i] && g_options_i[i][0])
	{
		if (ft_strcmp(str, g_options_i[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
