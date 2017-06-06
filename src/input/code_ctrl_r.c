/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_ctrl_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:13:29 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/24 19:22:31 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static void	display_missing(char *tmp, int *old_len)
{
	default_mode();
	tmp = &tmp[cor()->x];
	ft_putstr("\033[4;92m");
	ft_putstr(tmp);
	ft_putstr("\033[0m");
	*old_len = ft_strlen(tmp);
	move_left(*old_len);
}

void		code_ctrl_r(void)
{
	static int	old_len = 0;
	char		*pattern;
	t_list		*full_list;

	ft_strdel(found());
	fill_space(old_len);
	if (!(*search_mode()) && (*search_mode() = 1))
	{
		move_left(*prompt_len() + 1);
		prompt();
		return ;
	}
	pattern = **command() ? ft_strjoin(*command(), "*") : NULL;
	full_list = *get_full_list();
	while (pattern && full_list)
	{
		if (match((char *)full_list->content, pattern))
		{
			*found() = ft_strdup((char *)full_list->content);
			break ;
		}
		full_list = full_list->next;
	}
	*found() ? display_missing(*found(), &old_len) : 0;
	ft_strdel(&pattern);
}
