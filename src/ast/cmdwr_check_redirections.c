/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdwr_check_redirections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:09:44 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/08 15:30:45 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"

static	int		get_word(char *str)
{
	int		i;

	i = 0;
	while (str[i] && !tl_iswhitespace(str[i]))
	{
		if ((i == 0 || str[i - 1] != '\\') &&\
			(str[i] == '\'' || str[i] == '\"'))
			i += tl_jump_to_other_quote(str + i);
		i++;
	}
	return (i);
}

static size_t	get_to_fd(char *ptr)
{
	int		i;

	i = 0;
	while (ptr[i] && tl_iswhitespace(ptr[i]))
		i++;
	if (!ptr[i] || !(i += get_word(ptr + i)))
		return (0);
	return (i);
}

size_t			cmdwr_check_redirections(char *str, int *i, int redirection)
{
	size_t	len;
	size_t	tmp;

	len = 0;
	tmp = *i + (redirection == 0 || redirection == 1 ? 2 : 1);
	if (redirection == 0 || redirection == 1)
		len++;
	if ((*i == 1 || (*i > 1 && tl_iswhitespace(str[*i - 2]))) &&\
		ft_isdigit(str[*i - 1]))
	{
		len++;
		(*i)--;
	}
	if ((str[tmp] == '&') || (redirection == 1 && str[tmp] == '-'))
	{
		len++;
		tmp++;
	}
	len += get_to_fd(str + tmp);
	return (len);
}
