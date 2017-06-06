/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_substitution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:47:41 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/05 14:05:08 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "libft.h"
#include "tools.h"
#include "ft_42sh.h"

static char	*is_alias(t_variable *lst_alias, char *word)
{
	t_variable	*ptr;
	char		*key;

	if (!word)
		return (ERROR);
	ptr = lst_alias;
	while (ptr)
	{
		if ((key = var_getkey(ptr->variable)))
		{
			if (ft_strequ(key, word))
			{
				ft_strdel(&key);
				return (ptr->variable);
			}
			ft_strdel(&key);
		}
		ptr = ptr->next;
	}
	return (NULL);
}

static int	search_for_alias(t_variable *lst_alias, char **line,\
												char *initial_word, int *i)
{
	char	*value;
	char	*tmp_key;

	tmp_key = initial_word;
	while ((value = is_alias(lst_alias, tmp_key)))
	{
		value += ft_strlen(tmp_key) + 1;
		if (ft_strequ(initial_word, value))
			return (ERROR);
		else if (ft_strequ(tmp_key, value))
		{
			*line = tl_switch_string(*line, *i, value, initial_word);
			*i = *i + ft_strlen(value);
			return (GOOD);
		}
		tmp_key = value;
	}
	if (!ft_strequ(initial_word, tmp_key))
	{
		*line = tl_switch_string(*line, *i, tmp_key, initial_word);
		*i = ft_strlen(tmp_key) - ft_strlen(initial_word);
		return (GOOD);
	}
	return (ERROR);
}

static void	find_first_word(t_variable *lst_alias, char **line,\
													int *i, int first_word)
{
	int		end;
	char	*word;

	while ((*line)[*i] && (*line)[*i] != ';')
	{
		end = *i;
		while ((*line)[end] && !tl_iswhitespace((*line)[end])\
			&& (*line)[end] != ';')
		{
			if (((*line)[end] == '\"' || (*line)[end] == '\\') &&\
				(end == 0 || (end > 0 && (*line)[end - 1] != '\\')))
				end += tl_jump_to_other_quote(*line + end);
			end++;
		}
		if (first_word && (word = tl_strndup(*line + *i, (end - *i))))
		{
			search_for_alias(lst_alias, line, word, i);
			ft_strdel(&word);
		}
		if (((*line)[*i] == '\"' || (*line)[*i] == '\\') &&\
			(*i == 0 || (*i > 0 && (*line)[*i - 1] != '\\')))
			*i += tl_jump_to_other_quote(*line + *i);
		first_word = 0;
		(*i)++;
	}
}

int			alias_substitution(t_variable *lst_alias, char **line)
{
	int		i;
	int		len;

	if (!lst_alias)
		return (GOOD);
	len = ft_strlen(*line);
	i = 0;
	while (i < len)
	{
		while ((*line)[i] && tl_iswhitespace((*line)[i]))
			++i;
		find_first_word(lst_alias, line, &i, 1);
		while ((*line)[i] == ';')
			i++;
		len = ft_strlen(*line);
	}
	return (GOOD);
}
