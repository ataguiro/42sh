/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:32:34 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/09 13:06:47 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh_mem;

	fresh_mem = malloc(size);
	if (fresh_mem == NULL)
		return (NULL);
	ft_memset(fresh_mem, 0, size);
	return (fresh_mem);
}
