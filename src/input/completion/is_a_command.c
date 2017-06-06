/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:38:30 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/24 23:46:27 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include "input.h"

int				is_a_command(char *command)
{
	int		i;
	int		word;

	if (tl_isstrempty(command))
		return (1);
	word = 0;
	i = 0;
	while (command[i] && tl_iswhitespace(command[i]))
		++i;
	while (command[i] && !tl_iswhitespace(command[i]))
		++i;
	if (command[i] && is_delim_char(command, i++))
		word = 1;
	while (command[i])
	{
		if (!is_delim_char(command, i))
			word = 1;
		else if (word &&\
			command[i] == ';' && (i == 0 || command[i - 1] != '\\'))
			word = 0;
		++i;
	}
	return (word == 0 ? 1 : 0);
}
