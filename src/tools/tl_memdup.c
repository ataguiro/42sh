/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoac <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:19:26 by tpoac             #+#    #+#             */
/*   Updated: 2017/01/23 16:20:12 by tpoac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void		*tl_memdup(void const *dest, size_t n)
{
	void	*dup;

	if (!(dup = malloc(sizeof(unsigned char) * n)))
		return (NULL);
	ft_memcpy(dup, dest, n);
	return (dup);
}
