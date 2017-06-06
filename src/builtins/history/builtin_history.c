/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:28:18 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/20 13:20:06 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"
#include "history.h"
#include "builtin_history.h"

static int	call_function(t_hist_option tools, char **av)
{
	t_list			*lst;

	lst = *get_full_list();
	if (tools.option & OPTION_C)
		return (history_clear_list(&lst));
	else if (tools.option & OPTION_D)
		return (history_del_position_offset(&lst, tools, tools.offset));
	else if (tools.option & OPTION_S)
		return (history_option_s(av));
	else if (tools.option & OPTION_P)
		return (history_option_p(av));
	else if (tools.option & OPTION_R)
		return (history_append_file_to_list(av));
	else if (tools.option & OPTION_W)
		return (overwrite_history_file(lst));
	else if (tools.option & OPTION_A)
		return (save_history_in_file(*get_new_list()));
	else
		return (history_print_list(lst, av));
}

int			builtin_history(t_shell *sh, int ac, char **av)
{
	int				i;
	t_hist_option	tools;

	(void)sh;
	(void)ac;
	ft_bzero(&tools, sizeof(t_hist_option));
	if ((i = history_get_options(&tools, av)) == -1)
		return (1);
	return (call_function(tools, av + i));
}
