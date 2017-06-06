/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_closedir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:59:49 by fhuang            #+#    #+#             */
/*   Updated: 2016/11/30 14:02:09 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <dirent.h>

int			tl_closedir(DIR *dir)
{
	if (closedir(dir))
		return (ERROR);
	return (GOOD);
}
