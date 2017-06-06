/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_jump_to_other_quote.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:14:18 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/02 15:18:03 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	tl_jump_to_other_quote(char *ptr)
{
	char	c;
	size_t	i;

	i = 0;
	c = ptr[i++];
	while (ptr[i])
	{
		if (ptr[i] == c && ptr[i - 1] != '\\')
			break ;
		i++;
	}
	return (i);
}
