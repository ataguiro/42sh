/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sin_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:42:03 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/24 17:24:17 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "input.h"

t_termsize	*termsize(void)
{
	static t_termsize	new;
	struct winsize		w;

	ioctl(0, TIOCGWINSZ, &w);
	new.col = w.ws_col;
	new.row = w.ws_row;
	return (&new);
}

int			*search_mode(void)
{
	static int	search_mode = 0;

	return (&search_mode);
}

char		**found(void)
{
	static char	*found = NULL;

	return (&found);
}
