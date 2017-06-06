/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:38:21 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/08 15:46:48 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ret;

	ret = NULL;
	if (size)
	{
		ret = ft_memalloc(size);
		if (ptr)
		{
			ft_memcpy(ret, ptr, size);
			free(ptr);
		}
	}
	else
		free(ptr);
	return (ret);
}
