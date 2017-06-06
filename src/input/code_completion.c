/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_completion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:14:56 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/03 14:17:53 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include "expansion.h"
#include "input.h"

static int	step_back_2(void)
{
	int		i;

	i = cor()->x - ((*command())[cor()->x] == 0 ? 1 : 0);
	while (i >= 0 && !tl_iswhitespace((*command())[i]) &&\
		(*command())[i] != ';' && (*command())[i] != '&' &&\
		(*command())[i] != '|')
	{
		if ((*command())[cor()->x] != 0)
		{
			i++;
			cor()->x++;
			move_right(1);
		}
		stremove();
		--(i);
		if ((*command())[i] == 0)
			break ;
	}
	return (i);
}

static char	*step_back(char *save)
{
	int		end;
	int		i;

	if (!save)
		return (NULL);
	end = cor()->x - ((*command())[cor()->x] == 0 ? 1 : 0);
	i = end;
	while (end >= 0 && (*command())[end] && !is_delim_char(*command(), end))
		++end;
	while (cor()->x < cor()->len)
	{
		move_right(1);
		++cor()->x;
	}
	i = step_back_2();
	cor()->len = ft_strlen(*command());
	i = i < 0 ? 0 : i;
	end = end < i ? i : end;
	if ((*command())[i] == ';' || (*command())[i] == '&' ||\
		(*command())[i] == '|')
		++(i);
	return (tl_isstrempty(save) ?\
		ft_strnew(0) : tl_strndup(save + i, end - i + 1));
}

void		code_completion(void)
{
	t_list	*cursor;
	char	*save;
	char	*word;
	int		pos;

	save = ft_strdup(*command());
	pos = cor()->x;
	word = step_back(save);
	if ((cursor = *get_cursor_completion()))
	{
		if (!(*get_cursor_completion() = cursor->next))
			*get_cursor_completion() = *get_list_completion();
	}
	else
	{
		if (word && save && is_a_command(save) == 1)
			look_for_a_command(tl_isstrempty(save) ? "" : word);
		else if (word)
			look_for_a_file(word);
		*get_cursor_completion() = *get_list_completion();
	}
	display_command(&save, pos);
	ft_strdel(&word);
}
