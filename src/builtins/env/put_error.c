/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:44:50 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/09 15:44:50 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include "libft.h"

void	env_put_error(char *executable_name, char *error)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(executable_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error, 2);
}
