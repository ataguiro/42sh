/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:44:55 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/09 15:44:55 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include "libft.h"
#include <stdlib.h>

static	int	is_good_argument(char *str)
{
	char	*tmp;

	if (!ft_strchr(str, '='))
		return (1);
	tmp = ft_strjoin("unsetenv ", str);
	env_put_error(tmp, "Invalid argument");
	ft_strdel(&tmp);
	return (0);
}

static	int	is_same_key(char *key, char *env_line)
{
	int		key_len;

	key_len = ft_strlen(key);
	if (ft_strncmp(key, env_line, key_len) == 0 && env_line[key_len] == '=')
		return (1);
	return (0);
}

static	int	remove_key(char *key, char ***env)
{
	char	**new_env;
	int		i;
	int		j;

	if (!(env_key_exist(key, *env)))
		return (1);
	if (!(new_env = env_alloc_env(env_get_env_size(*env) - 1)))
		return (0);
	i = 0;
	j = 0;
	while (env[0][i])
	{
		if (!is_same_key(key, env[0][i]))
		{
			new_env[j] = env[0][i];
			j++;
		}
		else
			ft_strdel(&env[0][i]);
		i++;
	}
	new_env[j] = 0;
	free(*env);
	*env = new_env;
	return (1);
}

int			env_remove_key(int index, char **av, char ***env)
{
	if (av[index] == 0)
	{
		env_put_error("option requires an argument", av[index - 1]);
		env_print_usage();
		return (ERROR);
	}
	if (!is_good_argument(av[index]))
		return (ERROR);
	if (*env == 0)
		return (SUCCESS);
	if (!(remove_key(av[index], env)))
		return (ERROR);
	return (SUCCESS);
}
