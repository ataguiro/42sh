/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:53:06 by cjacquem          #+#    #+#             */
/*   Updated: 2016/11/24 12:53:22 by cjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**			This function returns the result of the merging of origin and adding
**			The origin is freed.
*/

#include "libft.h"
#include "tools.h"

char		*tl_strmerge(char *origin, char *adding)
{
	char	*merging;

	if (origin && !adding)
	{
		if (!(merging = ft_strdup(origin)))
			return (NULL);
		ft_strdel(&origin);
	}
	else if (!origin && adding)
	{
		if (!(merging = ft_strdup(adding)))
			return (NULL);
	}
	else if (origin && adding)
	{
		if (!(merging = ft_strjoin(origin, adding)))
			return (NULL);
		ft_strdel(&origin);
	}
	else
		merging = NULL;
	return (merging);
}
