/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matchpp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoac <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 20:42:50 by tpoac             #+#    #+#             */
/*   Updated: 2017/02/03 14:57:21 by tpoac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

static int			match_inside(const char *s1, char *letters)
{
	return ((letters[0] != '^'
				&& tl_cis(*s1, letters))
			|| (letters[0] == '^'
				&& !tl_cis(*s1, letters)));
}

static int			match_crochet(const char *s1, const char *s2)
{
	char			*letters;
	size_t			count_letters;

	if (ft_strlen(s2) > tl_strupto(s2, "]"))
		return (0);
	letters = ft_strsub(s2, 1, tl_strupto(s2, "]") - 2);
	if (match_inside(s1, letters))
	{
		count_letters = ft_strlen(letters);
		free(letters);
		return (matchpp(s1 + 1, s2 + (count_letters + 2)));
	}
	free(letters);
	return (0);
}

static int			match_accolade(const char *s1, const char *s2)
{
	char			**split_accolade;
	char			*sub_split;
	int				inc_i;

	inc_i = 0;
	if (ft_strlen(s2) > tl_strupto(s2, "}"))
		return (0);
	sub_split = ft_strsub(s2, 1, tl_strupto(s2, "}") - 2);
	split_accolade = ft_strsplit(sub_split, ',');
	free(sub_split);
	while (split_accolade[inc_i])
	{
		if (matchpp(s1, split_accolade[inc_i]))
		{
			tl_freedoubletab(split_accolade);
			return (1);
		}
		inc_i++;
	}
	tl_freedoubletab(split_accolade);
	return (0);
}

int					matchpp(const char *s1, const char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s1 == '\0' || *s2 == '\0')
		return (0);
	else if (*s2 == '[')
		return (match_crochet(s1, s2));
	else if (*s2 == '{')
	{
		if (match_accolade(s1, s2))
			return (1);
	}
	else if (*s1 == *s2 || *s2 == '?')
		return (matchpp(s1 + 1, s2 + 1));
	else if (*s2 == '*')
		return (matchpp(s1 + 1, s2) || matchpp(s1 + 1, s2 + 1));
	return (0);
}
