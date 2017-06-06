/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exclamation_mark.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:22:51 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/05 18:03:54 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include "ft_42sh.h"
#include "history.h"

/*
**	!
**	Start a history substitution, except when followed by a space,
**	tab, the end of the line, `=' or `('.
**	!n
**	Refer to command line n.
**	!-n
**	Refer to the command n lines back.
**	!!
**	Refer to the previous command. This is a synonym for `!-1'.
**	!string
**	Refer to the most recent command starting with string.
*/

static void	put_error_event(int event)
{
	ft_putstr_fd("42sh: !", 2);
	ft_putnbr_fd(event, 2);
	ft_putstr_fd(": event not found\n", 2);
}

static int	is_strdigitneg(char *str)
{
	if (!str)
		return (0);
	if (!ft_isdigit(str[0]) && str[0] != '-')
		return (0);
	else if (str[0] == '-' && !ft_isdigit(str[1]))
		return (0);
	return (1);
}

static char	*print_from_offset(char **cmd, int *i)
{
	t_list	*lst;
	char	*tmp;
	int		lst_index;
	int		offset;

	lst = *get_full_list();
	lst_index = 0;
	if ((offset = (*cmd)[*i + 1] == '!' ? -1 : ft_atoi(*cmd + *i + 1)) < 0)
		offset = ft_lstlen(lst) - (-offset);
	while (offset > 0 && lst && lst_index < offset)
	{
		lst_index++;
		lst = lst->next;
	}
	if (offset <= 0 || lst_index != offset || !lst || !lst->content)
	{
		put_error_event(ft_atoi(*cmd + *i + 1));
		ft_strdel(&(*cmd));
		return (NULL);
	}
	ft_putendl(lst->content);
	tmp = tl_strndup(*cmd + *i, ft_nbrlen(ft_atoi(*cmd + *i + 1)) + 1);
	*cmd = tl_switch_string(*cmd, *i, lst->content, tmp);
	return (tmp);
}

static char	*look_for_string(char **cmd, int *i)
{
	t_list	*lst;
	char	*tmp;
	size_t	len;

	tmp = NULL;
	lst = *get_full_list();
	len = ++(*i);
	while ((*cmd)[len + 1] && (*cmd)[len + 1] != ' ' && (*cmd)[len + 1] != '\t'
		&& (*cmd)[len + 1] != ';')
		++len;
	while (lst)
	{
		if (lst->content && !ft_strncmp(lst->content, *cmd + *i, len))
			tmp = tmp ? ft_strcpy(tmp, lst->content) : ft_strdup(lst->content);
		lst = lst->next;
	}
	if (!tmp)
	{
		ft_strdel(&(*cmd));
		ft_putstr_fd("42sh: No such word in event\n", 2);
		return (NULL);
	}
	*cmd = tl_switch_string(*cmd, *i - 1, tmp, *cmd + *i - 1);
	ft_putendl(tmp);
	return (((*i) += len) ? tmp : tmp);
}

char		*exclamation_mark(char *cmd)
{
	int		i;
	int		backslash;
	char	*ret;

	i = -1;
	ret = NULL;
	while (cmd[++i])
	{
		backslash = (i > 0 && cmd[i - 1] == '\\') ? 1 : 0;
		if (cmd[i] == '!' && backslash == 0 && cmd[i + 1] && cmd[i + 1] != '='\
			&& cmd[i + 1] != '\t' && cmd[i + 1] != ' ' && cmd[i + 1] != '(')
		{
			if (is_strdigitneg(cmd + i + 1) || cmd[i + 1] == '!')
			{
				if (!(ret = print_from_offset(&cmd, &i)))
					return (NULL);
			}
			else if (cmd[i + 1] != '#' && !(ret = look_for_string(&cmd, &i)))
				return (NULL);
			if (ret)
				ft_strdel(&ret);
		}
	}
	return (cmd);
}
