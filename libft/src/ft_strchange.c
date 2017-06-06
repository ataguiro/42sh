/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 13:58:35 by fhuang            #+#    #+#             */
/*   Updated: 2016/10/13 14:01:24 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchange(char *in, const char *bywhat)
{
	char	*tmp;

	tmp = in;
	in = ft_strdup(bywhat);
	ft_strdel(&tmp);
	return (in);
}
