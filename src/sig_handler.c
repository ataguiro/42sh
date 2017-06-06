/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:47:57 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/05 17:45:15 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/wait.h>
#include "ft_42sh.h"
#include "input.h"

extern	pid_t	g_id;

static void	reset_input(void)
{
	int	status;

	default_mode();
	code_end();
	*found() ? fill_space(ft_strlen(*found())) : 0;
	ft_putchar('\n');
	if (waitpid(g_id, &status, 0) != -1)
	{
		if (g_id != -1)
			kill(g_id, SIGKILL);
	}
	else
		prompt();
	ft_strdel(command());
	*command() = ft_strdup("");
	ft_strdel(stock());
	*stock() = ft_strdup("");
	ft_strdel(found());
	reset_quotes();
	raw_mode();
	*search_mode() = 0;
	cor()->len = 0;
	cor()->x = 0;
	clear_completion();
}

static void	sigquit_handler(void)
{
	int	status;

	if (waitpid(g_id, &status, 0) != -1)
	{
		if (g_id != -1)
			kill(g_id, SIGKILL);
		ft_putchar('\n');
	}
}

void		sig_handler(int signo)
{
	if (signo == SIGINT)
		reset_input();
	else if (signo == SIGQUIT)
		sigquit_handler();
	else if (signo == SIGTERM || signo == SIGKILL)
	{
		default_mode();
		exit(signo);
	}
}
