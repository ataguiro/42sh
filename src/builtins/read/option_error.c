/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:51:57 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/14 19:55:01 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_42sh.h"

int		read_option_error(char *str, char *msg)
{
	ft_putstr_fd("42sh: read: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
	return (ERROR);
}
