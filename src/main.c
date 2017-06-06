/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:19:48 by yfuks             #+#    #+#             */
/*   Updated: 2017/02/05 15:26:18 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "tools.h"
#include "libft.h"
#include "ast.h"
#include "expansion.h"
#include <signal.h>
#include <stdio.h>
#include "history.h"
#include "input.h"

t_shell		g_sh;

static void		clear_main(char **line, t_list **lst)
{
	if (*line)
	{
		ft_strclr(*line);
		ft_strdel(line);
	}
	if (*lst)
		tl_lstdelast(lst);
}

static void		call_signal(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	signal(SIGTERM, sig_handler);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGCONT, SIG_IGN);
}

static void		gear(t_shell *sh, t_list *lst_commands)
{
	if (ft_strchr(*command(), '!'))
		if (!(*command() = exclamation_mark(*command())))
			return ;
	save_command_line(*command());
	alias_substitution(sh->lst_alias, command());
	lexer_parser(command(), &lst_commands);
	loop_through_commands(sh, lst_commands);
	clear_main(command(), &lst_commands);
}

int				main(int ac, char **av)
{
	t_shell		sh;
	t_list		*lst_commands;

	if (isatty(STDIN_FILENO) != 1)
		exit(0);
	lst_commands = NULL;
	if (ac && !init_shell(&sh, av[0]))
		return (ERROR);
	while (prompt())
	{
		call_signal();
		g_sh = sh;
		if (input() == 0)
			gear(&sh, lst_commands);
		else
		{
			clear_main(command(), &lst_commands);
			ft_putendl("exit");
			clear_shell(&sh);
			exit(EXIT_SUCCESS);
		}
	}
	return (GOOD);
}
