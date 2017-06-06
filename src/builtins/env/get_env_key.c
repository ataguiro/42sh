/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:43:40 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/09 15:43:41 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include "libft.h"

char	*env_get_env_key(char *str)
{
	char	*key;
	char	*equalsign;

	key = ft_strdup(str);
	equalsign = ft_strchr(key, '=');
	equalsign[0] = 0;
	return (key);
}
