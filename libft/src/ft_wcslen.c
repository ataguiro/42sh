/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 15:43:06 by fhuang            #+#    #+#             */
/*   Updated: 2016/06/17 15:47:29 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wcslen(const wchar_t *wstr)
{
	wchar_t		*ptr;

	ptr = (wchar_t*)wstr;
	while (*ptr)
		ptr++;
	return ((size_t)(ptr - wstr));
}
