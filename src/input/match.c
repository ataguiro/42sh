/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:35:30 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/31 12:47:32 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "tools.h"

int			match(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	if (*s1 == 0 && *s2 == 0)
		return (1);
	if (*s1 != 0 && *s2 == '*')
		return (match(s1, s2 + 1) || (match(s1 + 1, s2)));
	if (*s1 == 0 && *s2 == '*')
		return (match(s1, s2 + 1));
	if (*s2 == *s1)
		return (match(s1 + 1, s2 + 1));
	return (0);
}
