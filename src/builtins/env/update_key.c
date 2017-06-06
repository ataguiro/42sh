/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:45:05 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/09 15:45:05 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include "libft.h"
#include <stdlib.h>

static	int	found_line_with_key(char *key, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(key, env[i], ft_strlen(key)) == 0)
			return (i);
		i++;
	}
	return (0);
}

int			env_update_key(char *key, char *str, char **env)
{
	int		line;
	char	*tmp;

	line = found_line_with_key(key, env);
	tmp = env[line];
	env[line] = ft_strdup(str);
	free(tmp);
	return (0);
}
