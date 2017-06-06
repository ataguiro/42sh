/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_is_executable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:07:18 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/10 19:58:29 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <sys/stat.h>

int	exec_is_executable(char *filepath)
{
	struct stat	buff;

	if (stat(filepath, &buff) == 0 && buff.st_mode & S_IXUSR)
		return (1);
	return (0);
}
