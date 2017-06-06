/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstvariable_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:55:35 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/19 17:06:13 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "environment.h"

size_t	lstvariable_len(t_variable *lstvariable)
{
	size_t	i;

	i = 0;
	while (lstvariable)
	{
		i++;
		lstvariable = lstvariable->next;
	}
	return (i);
}
