/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:45:01 by yfuks             #+#    #+#             */
/*   Updated: 2016/12/08 15:55:46 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include "libft.h"
#include <stdlib.h>

static	void	shift_str(char *str, int index)
{
	while (str[index])
	{
		str[index] = str[index + 1];
		index++;
	}
}

static	void	remove_duplicate_equals(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=' && str[i + 1] == '=')
		{
			shift_str(str, i);
			i--;
		}
		else if (str[i] == '=')
			break ;
		i++;
	}
}

int				env_set_env(char *str, char ***env)
{
	char	*key;

	remove_duplicate_equals(str);
	key = env_get_env_key(str);
	if (env_key_exist(key, *env))
		env_update_key(key, str, *env);
	else
		env_add_key(str, env);
	free(key);
	return (0);
}
