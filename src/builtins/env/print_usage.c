/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:44:44 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/09 15:44:44 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include "libft.h"

void	env_print_usage(void)
{
	ft_putendl_fd("usage: env [- -i --ignore-environment] [-u name]", 2);
	ft_putendl_fd("           [name=value ...] [utility [argument ...]]", 2);
}
