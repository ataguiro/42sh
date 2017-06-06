/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:18:18 by cjacquem          #+#    #+#             */
/*   Updated: 2017/01/13 16:28:41 by cjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cd_error(int index, char *path)
{
	const char	*error_msg[] = {
		"Too many arguments.\n",
		"'HOME' variable not set.\n",
		"'OLDPWD' variable not set.\n",
		": No such file or directory.\n",
		": Not a directory.\n",
		": Permission denied.\n",
		NULL
	};

	ft_putstr_fd("42sh: cd: ", 2);
	if (index > 2 && index < 6 && path)
		ft_putstr_fd(path, 2);
	ft_putstr_fd(error_msg[index], 2);
	return (1);
}
