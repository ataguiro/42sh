/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:45:47 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/01 16:19:49 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static void	display_second_prompt(void)
{
	init_input();
	if (*bs())
	{
		cor()->prompt_len = 2;
		ft_putstr("> ");
	}
	else if (*dquote() % 2)
	{
		cor()->prompt_len = 8;
		ft_putstr("dquote> ");
	}
	else if (*quote() % 2)
	{
		cor()->prompt_len = 7;
		ft_putstr("quote> ");
	}
	else if (*lbracket())
	{
		cor()->prompt_len = 2;
		ft_putstr("> ");
	}
}

static int	manage_return(void)
{
	if (!(*dquote() % 2) && !(*quote() % 2) && !(*bs()) && !(*lbracket()))
	{
		reset_quotes();
		!ft_strcmp(*stock(), *command()) || !(**stock()) ? ft_putchar('\n') : 0;
		ft_strdel(command());
		*command() = ft_strdup(*stock());
		ft_strdel(stock());
		return (0);
	}
	else
		display_second_prompt();
	return (1);
}

static void	return_issue(void)
{
	manage_quotes();
	if ((*dquote() % 2 && *dquote()) || (*quote() % 2 && *quote())
				|| *bs() || *lbracket())
	{
		code_end();
		manage_command('\n');
	}
	*stock() = tl_strmerge(*stock(), *command());
	manage_quotes();
}

int			input(void)
{
	int		key;
	int		ret;

	key = 0;
	init_input();
	while (1)
	{
		cor()->len = ft_strlen(*command());
		key = key_get();
		if (key == -3)
			continue ;
		if (key != 1)
			clear_completion();
		(key != -42) ? key_dump(key) : 0;
		if (!key)
		{
			return_issue();
			ret = manage_return();
			default_mode();
			if (!ret)
				return (0);
		}
		if (key == -1 && !(*command() && (*command())[0]) && !cor()->len)
			return (1);
	}
}
