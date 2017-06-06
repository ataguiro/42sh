/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:43:00 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/10 15:38:24 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include <stdlib.h>
#include "libft.h"

int		env_add_key(char *str, char ***env)
{
	int		env_size;
	char	**tmp_env;
	int		i;

	env_size = env_get_env_size(*env);
	tmp_env = env_alloc_env(env_size + 2);
	i = 0;
	while (i < env_size)
	{
		tmp_env[i] = env[0][i];
		i++;
	}
	tmp_env[env_size] = ft_strdup(str);
	tmp_env[env_size + 1] = 0;
	free(*env);
	*env = tmp_env;
	return (0);
}
