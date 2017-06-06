/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynam_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 12:00:55 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/24 12:01:01 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dynam_append(t_dynam *dyn, void *new_d, size_t nb)
{
	size_t	mult;
	void	*tmp;

	if (dyn->data == NULL)
	{
		if (!(dyn->data = malloc(dyn->t_size * nb)))
			return (1);
		dyn->max_elem = nb;
		dyn->nb_elem = 0;
	}
	mult = 1;
	while (nb + dyn->nb_elem > mult * dyn->max_elem)
		mult *= 2;
	if (mult > 1)
	{
		dyn->max_elem *= mult;
		if (!(tmp = malloc(dyn->max_elem * dyn->t_size)))
			return (1);
		ft_memcpy(tmp, dyn->data, (dyn->nb_elem * dyn->t_size));
		free(dyn->data);
		dyn->data = tmp;
	}
	ft_memcpy(dyn->data + dyn->nb_elem * dyn->t_size, new_d, nb * dyn->t_size);
	dyn->nb_elem += nb;
	return (0);
}
