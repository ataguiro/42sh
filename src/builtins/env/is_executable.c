/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_executable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:43:58 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/09 15:43:58 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include <sys/stat.h>

int		env_is_executable(char *filepath)
{
	struct stat	buff;

	if (stat(filepath, &buff) == 0 && buff.st_mode & S_IXUSR)
		return (1);
	return (0);
}
