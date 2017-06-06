/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 21:28:31 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/01 21:29:37 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	uin;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		uin = (unsigned int)-n;
	}
	else
		uin = (unsigned int)n;
	if (uin >= 10)
		ft_putnbr_fd(uin / 10, fd);
	ft_putchar_fd(uin % 10 + '0', fd);
}
