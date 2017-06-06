/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_exist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:44:18 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/09 15:44:20 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"

int		env_key_exist(char *key, char **env)
{
	int		i;
	int		key_len;

	if (env == 0)
		return (0);
	i = 0;
	key_len = ft_strlen(key);
	while (env[i])
	{
		if (ft_strncmp(key, env[i], key_len) == 0 && env[i][key_len] == '=')
			return (1);
		i++;
	}
	return (0);
}
