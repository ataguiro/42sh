/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_a_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 12:18:44 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/31 12:40:37 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include "input.h"

int		look_for_a_file(char *command)
{
	int		len;
	char	*dir_name;
	char	*tmp;

	len = ft_strlen(command) - 1;
	while (len >= 0 && command[len] != '/')
		--len;
	if (len == -1)
	{
		dir_name = ft_strdup(".");
		++len;
	}
	else
	{
		command[len] == '/' ? ++len : 0;
		tmp = tl_strndup(command, len);
		dir_name = ft_strtrim(tmp);
		ft_strdel(&tmp);
	}
	len = search_through_dir(dir_name, command + len);
	ft_strdel(&dir_name);
	return (len);
}
