/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:06:28 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/11 19:11:07 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include "environment.h"
#include "libft.h"

char	*env_get_paths(char **env)
{
	char		*paths;

	if (!(paths = env_get_env_value("PATH", env)))
		paths = ft_strdup(DEFAULT_PATH);
	return (paths);
}
