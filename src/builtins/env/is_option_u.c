/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_option_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:44:13 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/09 16:45:02 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include "libft.h"

static	const	char	g_options_u[][3] = {
	{"-u"},
	{0}
};

int		env_is_option_u(char *str)
{
	int		i;

	i = 0;
	while (g_options_u[i] && g_options_u[i][0])
	{
		if (ft_strcmp(str, g_options_u[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
