/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:06:57 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/04 15:04:57 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int		get_basics(char c)
{
	if (c == '\x9')
		return (CODE_TAB);
	if (c == '\x4' && !(*quote() % 2) && !(*dquote() % 2))
		return (CODE_CTRL_D);
	if (c == '\x18')
		return (CODE_CTRL_X);
	if (c == '\x15')
		return (CODE_CTRL_U);
	if (c == '\x17')
		return (CODE_CTRL_W);
	if (c == '\x7f')
		return (CODE_BACK);
	if (c == '\x0C')
		return (CODE_CTRL_L);
	if (c == '\x12')
		return (CODE_CTRL_R);
	if (c == '\xa')
		return (CODE_RETURN);
	return (-42);
}

int		get_x1b(char c)
{
	if (c == '\x5b')
	{
		read(0, &c, 1);
		if (c == '\x41')
			return (CODE_UP);
		if (c == '\x42')
			return (CODE_DOWN);
		if (c == '\x43')
			return (CODE_RIGHT);
		if (c == '\x44')
			return (CODE_LEFT);
		if (c == '\x48')
			return (CODE_HOME);
		if (c == '\x46')
			return (CODE_END);
		if (c == '\x31')
		{
			read(0, &c, 1);
			return (get_x31(c));
		}
	}
	return (-42);
}

int		get_x31(char c)
{
	if (c == '\x3b')
	{
		read(0, &c, 1);
		if (c == '\x32')
		{
			read(0, &c, 1);
			if (c == '\x41')
				return (CODE_SHIFT_UP);
			if (c == '\x42')
				return (CODE_SHIFT_DOWN);
			if (c == '\x43')
				return (CODE_SHIFT_RIGHT);
			if (c == '\x44')
				return (CODE_SHIFT_LEFT);
		}
	}
	return (-42);
}
