/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_is_a_directory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:31:42 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/24 16:35:18 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

int		tl_is_a_directory(char *path)
{
	struct stat	buf;

	if (stat(path, &buf) == -1)
		return (0);
	return (S_ISDIR(buf.st_mode) == 1 ? 1 : 0);
}
