/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:42:00 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/25 00:55:25 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	strinsert_input(char c)
{
	char	*new;
	char	*to_add;

	to_add = NULL;
	new = ft_strnew(ft_strlen(*command()) + 2);
	new = ft_strcpy(new, *command());
	to_add = strdup_input(&new[cor()->x]);
	new[cor()->x] = c;
	new[cor()->x + 1] = 0;
	default_mode();
	ft_putchar(c);
	raw_mode();
	if (cor()->x != cor()->len)
	{
		ft_putstr(to_add);
		move_left(ft_strlen(to_add));
	}
	ft_strdel(command());
	*command() = ft_strjoin(new, to_add);
	ft_strdel(&to_add);
	ft_strdel(&new);
}

void	fill_space(int j)
{
	int	i;

	i = 0;
	while (i < j + 1)
	{
		ft_putchar(' ');
		i++;
	}
	move_left(j + 1);
}

void	stremove(void)
{
	char	*cleaner;
	char	*to_add;
	char	*tmp;

	if (!(*command() && (*command())[0]))
		return ;
	if (cor()->x > 0)
	{
		to_add = ((*command()) + cor()->x);
		(cor()->x)--;
		move_left(1);
		remove_display(to_add);
		(*command())[cor()->x] = 127;
		if (*command())
		{
			tmp = strdup_input(*command());
			free(*command());
			*command() = tmp;
		}
		cleaner = NULL;
		ft_strclr(to_add);
		to_add = NULL;
	}
}

void	manage_command(char c)
{
	strinsert_input(c);
	(cor()->x)++;
}
