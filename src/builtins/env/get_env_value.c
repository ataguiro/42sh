/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:43:52 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/09 15:43:54 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include "libft.h"

char	*env_get_env_value(char *key, char **env)
{
	int		i;
	char	*value;

	value = 0;
	if (env == 0)
		return (0);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(key, env[i], ft_strlen(key)) == 0)
			return (ft_strdup(ft_strchr(env[i], '=') + 1));
		i++;
	}
	return (value);
}
