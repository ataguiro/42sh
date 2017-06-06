/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_print_command_error.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:36:33 by yfuks             #+#    #+#             */
/*   Updated: 2016/12/08 17:38:26 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libft.h"

static	void	print_error(char *message, char *command_name)
{
	ft_putstr_fd("42sh: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(command_name, 2);
}

int				exec_print_command_error(int error, char *command_name)
{
	if (error == NOTFOUND)
		print_error("command not found", command_name);
	else if (error == CANNOTINVOKE)
		print_error("permission denied", command_name);
	else if (error == ISDIRECTORY)
		print_error(command_name, "is a directory");
	else if (error == NOSUCHFILE)
		print_error("no such file or directory", command_name);
	else if (error == TOOLONG)
		print_error("command too long", command_name);
	else if (error == PERMISSIONDENIED)
	{
		print_error("permission denied", command_name);
		return (1);
	}
	else if (error == BADFILEDESCRIPTOR)
	{
		print_error(command_name, "bad file descriptor");
		return (1);
	}
	return (error);
}
