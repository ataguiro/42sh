/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:58:09 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/19 14:53:58 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "libft.h"
#include "tools.h"
#include "ft_42sh.h"

/*
**	This funciton check parse the tree and check
**	if operator node have a left and a right.
**	If not, a syntax error is occured.
*/

static int	parse_error(const char *str, char c)
{
	ft_putstr_fd("42sh: parse error near `", 2);
	if (str)
		ft_putstr_fd(str, 2);
	else
		ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
	return (ERROR);
}

static int	is_operator(char *str, int i, _Bool word)
{
	static const char	*redir[] = {">>", "<<", ">", "<", NULL};
	int					j;

	j = 0;
	while ((i == 0 || str[i - 1] != '\\') && redir[++j])
		if (ft_strnequ(redir[j], str + i, ft_strlen(redir[j])))
		{
			i += ft_strlen(redir[j]);
			if (word == 0 || tl_isstrempty(str + i) ||\
				(str[i] == '&' && !str[i + 1]) ||\
				(j == 1 && str[i] == '-' && !str[i + 1]))
				return (parse_error(redir[j], 0));
			else
				return (parse_str(str + i + 1));
		}
	return (GOOD);
}

int			parse_str(char *str)
{
	int					i;
	int					ret;
	_Bool				word;

	i = 0;
	while (str[i] && tl_iswhitespace(str[i]))
		i++;
	word = 0;
	while (str[i])
	{
		if ((i == 0 || str[i - 1] != '\\') &&\
			(str[i] == '\'' || str[i] == '\"') && (word = 1))
			i += tl_jump_to_other_quote(str + i);
		else if (!(ret = is_operator(str, i, word)))
			return (ERROR);
		if (!tl_iswhitespace(str[i]))
		{
			word = 1;
			i++;
		}
		else
			i++;
	}
	return (GOOD);
}

int			ast_parse_tree(t_ast *root)
{
	if (!root)
		return (GOOD);
	if (root->operator == COMMAND &&\
		(ft_strchr(root->str, '>') || ft_strchr(root->str, '<')))
	{
		if (!parse_str(root->str))
			return (ERROR);
		return (GOOD);
	}
	else if (root->operator != COMMAND)
	{
		if (!ast_parse_tree(root->left))
			return (ERROR);
		if (!ast_parse_tree(root->right))
			return (ERROR);
		else if (!root->left || !root->right)
			return (parse_error(root->str, 0));
	}
	return (GOOD);
}
