/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:43:26 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/09 15:43:28 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include <stdlib.h>
#include "libft.h"

void	env_free_env(char ***env)
{
	int		i;

	i = 0;
	if (*env == 0)
		return ;
	while (env[0][i])
	{
		free(env[0][i]);
		i++;
	}
	free(*env);
	*env = 0;
}
