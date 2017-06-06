/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:27:22 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/05 17:33:46 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_42sh.h"
#include "tools.h"

#define SQUOTE_OPEN (bf.squote % 2) == 1
#define DQUOTE_OPEN (bf.dquote % 2) == 1

static char		*remove_newlines(char *cmd, int *i)
{
	int		tmp;

	tmp = *i;
	while (cmd[tmp + 1])
	{
		cmd[tmp] = cmd[tmp + 1];
		++(tmp);
	}
	ft_strclr(cmd + tmp);
	--(*i);
	return (cmd);
}

char			*remove_quotes_and_backslash(char *cmd)
{
	int			i;
	t_bitfield	bf;

	i = -1;
	ft_bzero(&bf, sizeof(t_bitfield));
	while (cmd[++i])
	{
		if (cmd[i] == '\n' && i > 0 && cmd[i - 1] == '\\' && !(SQUOTE_OPEN))
			cmd = remove_newlines(cmd, &i);
		bf.bslash = (i > 0 && cmd[i - 1] == '\\' && !(SQUOTE_OPEN)) ? 1 : 0;
		if (cmd[i] == '\\' && !(SQUOTE_OPEN) && cmd[i + 1] == '\\' && (i++))
			cmd[i] = 127;
		else if (!(SQUOTE_OPEN) && !(DQUOTE_OPEN) && cmd[i] == '\\' &&\
			cmd[i + 1] != '\'' && cmd[i + 1] != '\"' && cmd[i + 1] != '\n')
			cmd[i] = 127;
		else if (((cmd[i] == '\'' && !(DQUOTE_OPEN)) ||\
			(cmd[i] == '\"' && !(SQUOTE_OPEN))))
		{
			bf.bslash == 0 && cmd[i] == '\'' ? (bf.squote)++ : (bf.dquote)++;
			cmd[i - bf.bslash] = 127;
		}
	}
	return (tl_strcpy_w_blank(cmd));
}
