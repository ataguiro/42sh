/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_getkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:19:57 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/19 17:37:19 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "libft.h"
#include "tools.h"

/*
**		Get the string before the first equal character found.
**		The returned string should be freed.
*/

char		*var_getkey(char *variable)
{
	char	*tmp;

	if ((tmp = ft_strchr(variable, '=')))
		return (tl_strndup(variable, (size_t)(tmp - variable)));
	return (NULL);
}
