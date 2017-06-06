/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <cjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:39:33 by cjacquem          #+#    #+#             */
/*   Updated: 2017/02/05 14:39:19 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**			The substitute function change $key by the value in environment and
**			the tilde ~ by the path of home.
**			Be careful with the simple quotes.
*/

#include "ft_42sh.h"
#include "tools.h"
#include "libft.h"
#include "execution.h"
#include "expansion.h"

static char	*dollar_and_tilde(t_shell *sh, char *cmd)
{
	size_t	i;
	int		double_quote;
	int		backslash;

	i = 0;
	double_quote = -1;
	while (cmd[i])
	{
		backslash = (i > 0 && cmd[i - 1] == '\\') ? 1 : 0;
		double_quote = cmd[i] == '\"' && !backslash ?\
			-double_quote : double_quote;
		if (cmd[i] == '$' && cmd[i + 1] && backslash == 0)
		{
			cmd = dollar(sh, cmd, cmd + i);
			i = -1;
		}
		else if (cmd[i] == '~' && backslash == 0)
			tilde(&cmd);
		else if (cmd[i] == '\'' && backslash == 0 && double_quote == -1)
			i += tl_jump_to_other_quote(cmd + i);
		i++;
	}
	return (cmd);
}

char		*substitute(t_shell *sh, char *cmd)
{
	if (cmd && (ft_strchr(cmd, '$') || ft_strchr(cmd, '~')))
		cmd = dollar_and_tilde(sh, cmd);
	if (cmd && (ft_strchr(cmd, '\\') || ft_strchr(cmd, '\'') ||\
		ft_strchr(cmd, '\"')))
		cmd = remove_quotes_and_backslash(cmd);
	return (cmd);
}
