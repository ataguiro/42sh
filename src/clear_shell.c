/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <cjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:00:33 by cjacquem          #+#    #+#             */
/*   Updated: 2017/01/23 20:53:07 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "environment.h"
#include "history.h"
#include "tools.h"
#include "input.h"

/*
**	This function free every variable in the shell structure
**	and set pointers to NULL.
*/

void	clear_shell(t_shell *sh)
{
	sh->last_return = 0;
	tl_lstfree(get_list_completion());
	clear_history_list();
	clear_env_list(&sh->lst_env);
	clear_env_list(&sh->lst_localvar);
	clear_env_list(&sh->lst_alias);
	ft_strdel(&sh->bin_path);
}
