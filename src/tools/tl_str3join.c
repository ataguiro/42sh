/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_str3join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:48:03 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/08 16:48:03 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"

/*
**		This function is joining three strings. None of them must be allocated.
**		The returned string should be freed at the end of its use.
*/

char		*tl_str3join(char *s1, char *s2, char *s3)
{
	char	*ret;

	if (!s1 || !s2 || !s3)
		return (NULL);
	ret = tl_strndup(s1, ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3));
	if (ret == NULL)
		return (NULL);
	ret = ft_strcat(ret, s2);
	ret = ft_strcat(ret, s3);
	return (ret);
}
