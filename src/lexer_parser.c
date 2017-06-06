/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <cjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:34:14 by cjacquem          #+#    #+#             */
/*   Updated: 2017/02/03 14:25:23 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**				first_lexer splits the command line in part with ; in delimiter
**				The simple and double quote and the backslash are considered.
*/

#include "ft_42sh.h"
#include "tools.h"
#include "libft.h"
#include "ast.h"

#define QUOTE_PROMPT "quote> "

static int		add_elem(t_list **lst, char *command, size_t size)
{
	char		*tmp;
	char		*tmp_trim;
	t_list		*elem;
	t_ast		*ast;

	if (!(tmp = tl_strndup(command, size)))
		return (ERROR);
	if (!(tmp_trim = ft_strtrim(tmp)))
		return (ERROR);
	ft_strdel(&tmp);
	ast = NULL;
	if ((ast = line_to_ast(tmp_trim)))
	{
		elem = NULL;
		if (!(elem = tl_lstnew(ast, sizeof(t_ast))))
			return (ERROR);
		tl_lstaddend(lst, elem);
	}
	ft_strdel(&tmp_trim);
	return (GOOD);
}

static int		check_inhibitors(t_list **lst, char **command, size_t *i)
{
	char		c;

	if ((*command)[*i] == '\\')
	{
		if ((*command)[*i + 1] == 0)
		{
			if (*lst)
				tl_lstdelast(lst);
			ft_putstr_fd("Unmatched \\.\n", 2);
			return (ERROR);
		}
		(*i)++;
	}
	if (((*command)[*i] == '\'' || (*command)[*i] == '\"') &&\
		(*i == 0 || (*i > 0 && (*command)[*i - 1] != '\\')))
	{
		c = (*command)[*i];
		*i += tl_jump_to_other_quote((*command) + *i);
	}
	return (GOOD);
}

int				lexer_parser(char **command_line, t_list **lst)
{
	size_t		i;
	size_t		index;

	i = -1;
	index = 0;
	while ((*command_line)[++i])
	{
		if (!check_inhibitors(lst, command_line, &i))
			return (ERROR);
		if ((*command_line)[i] == '#' &&\
			(i == 0 || (i > 0 && tl_iswhitespace((*command_line)[i - 1]))) &&\
			(i == 0 || i == 1 || (i > 1 && (*command_line)[i - 2] != '\\')))
			ft_strclr(*command_line + i);
		if ((*command_line)[i] == ';' &&\
			(i == 0 || (i > 0 && (*command_line)[i - 1] != '\\')))
		{
			if (!add_elem(lst, (*command_line) + index, i - index))
				return (ERROR);
			index = i + 1;
		}
	}
	return (i != index ? add_elem(lst,\
		(*command_line) + index, i - index) : GOOD);
}
