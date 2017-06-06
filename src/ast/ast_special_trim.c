/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_special_trim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:48:27 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/03 14:25:48 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ast.h"

char	*ast_special_trim(char *s)
{
	int		i;
	int		end;

	i = 0;
	end = ft_strlen(s) - 1;
	while (s[i] != '\0' && ast_special_is_space((int)s[i]) == 1)
		i++;
	if (s[i] == '\0')
		return (ft_strdup((char*)s + i));
	while (ast_special_is_space((int)s[end]) == 1)
		end--;
	return (ft_strndup((char*)s + i, ++end - i));
}
