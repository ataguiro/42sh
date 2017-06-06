/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:44:02 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/09 15:44:03 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include "libft.h"

int		env_is_option(char *str)
{
	if (env_is_option_i(str) || env_is_option_u(str))
		return (1);
	if (str[0] == '-')
		return (1);
	return (0);
}
