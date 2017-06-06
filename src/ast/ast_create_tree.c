/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_create_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:10:39 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/08 15:46:27 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ast.h"
#include "tools.h"

/*
**	This function parse the given string to create the tree.
**	Each node are delimited by shell operators.
**	Delimiters are "&&", "||", and "|".
**
**	The tree is returned.
*/

static int	is_operator(t_ast **lst_tokens, char *ptr, size_t *i, char *tmp)
{
	static const char	*ope[] = {"&&", "||", "|", NULL};
	int					j;
	size_t				len;

	j = 0;
	len = 0;
	while ((*i == 0 || ptr[*i - 1] != '\\') && ope[j])
	{
		if (ft_strnequ(ope[j], ptr + *i, ft_strlen(ope[j])))
		{
			if (ptr + *i != tmp)
				ast_create_elem(lst_tokens, -1,\
					tl_strndup(tmp, (size_t)(ptr + *i - tmp)));
			ast_create_elem(lst_tokens, j,\
				tl_strndup(ptr + *i, ft_strlen(ope[j]) + len));
			*i += ft_strlen(ope[j]) + len;
			return (j);
		}
		j++;
	}
	return (-1);
}

t_ast		*ast_create_tree(char *line)
{
	t_ast				*lst_tokens;
	size_t				i;
	char				*tmp;

	lst_tokens = NULL;
	i = 0;
	tmp = line;
	while (line[i])
	{
		if ((i == 0 || line[i - 1] != '\\') &&\
			(line[i] == '\'' || line[i] == '\"'))
			i += tl_jump_to_other_quote(line + i) + 1;
		else if (is_operator(&lst_tokens, line, &i, tmp) != -1)
			tmp = line + i;
		else
			i++;
	}
	if (tmp != line + i)
		ast_create_elem(&lst_tokens, -1,\
			tl_strndup(tmp, (size_t)(line + i - tmp)));
	return (lst_tokens);
}
