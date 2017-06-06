/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_is_directory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:13:42 by yfuks             #+#    #+#             */
/*   Updated: 2016/12/08 16:01:00 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <sys/stat.h>

int		exec_is_directory(char *filepath)
{
	t_stat	path_stat;

	stat(filepath, &path_stat);
	return ((path_stat.st_mode & S_IFMT) == S_IFDIR);
}
