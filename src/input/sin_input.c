/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sin_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:40:08 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/24 17:18:26 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

char	**command(void)
{
	static char	*command = NULL;

	return (&command);
}

char	**old_command(void)
{
	static char	*old_command = NULL;

	return (&old_command);
}

char	**copied(void)
{
	static char	*copied = NULL;

	return (&copied);
}

int		*prompt_len(void)
{
	static int	len = 0;

	return (&len);
}

t_coord	*cor(void)
{
	static t_coord	cor;

	return (&cor);
}
