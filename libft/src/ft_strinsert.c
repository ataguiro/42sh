/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 14:32:57 by fhuang            #+#    #+#             */
/*   Updated: 2016/10/11 14:36:18 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinsert(char *str, char *to_insert, int where)
{
	char	*after_insert;
	char	*ret;

	if (!(after_insert = ft_strdup(str + where)))
		return (NULL);
	ft_strclr(str + where);
	if (!(ret = ft_str3cat(str, to_insert, after_insert)))
		return (NULL);
	ft_strdel(&after_insert);
	return (ret);
}
