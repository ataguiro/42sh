/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_whitespace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:33:25 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/08 12:58:30 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static int	count_words2(char *s)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != 0)
			count++;
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != 0)
			i++;
	}
	return (count);
}

static int	count_char2(char *s)
{
	int		count;

	count = 0;
	while (s[count])
	{
		if (s[count] == ' ' || s[count] == '\t' || s[count] == '\n')
			break ;
		count++;
	}
	return (count);
}

char		**ft_strsplit_whitespace(char *s)
{
	t_infos2	info;

	if (!s)
		return ((char **)ft_memalloc(0));
	replace_with_shit(&s);
	info.words = count_words2(s);
	info.new = (char **)ft_memalloc(sizeof(char *) * (info.words + 2));
	info.i = 0;
	info.t = 0;
	if (!info.new)
		return (NULL);
	while (info.t < info.words)
	{
		while (s[info.i] != 0 && (s[info.i] == ' ' || s[info.i] == '\t' ||
					s[info.i] == '\n'))
			info.i++;
		info.new[info.t] = ft_strsub(&s[info.i], 0, count_char2(&s[info.i]));
		info.t++;
		while (s[info.i] != 0 && s[info.i] != ' ' && s[info.i] != '\t' &&
				s[info.i] != '\n')
			info.i++;
	}
	info.new[info.words] = NULL;
	remove_shit(&info.new);
	return (info.new);
}
