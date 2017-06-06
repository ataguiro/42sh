/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_shit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 22:06:12 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/14 15:51:11 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

char	*ft_get_clean(char *s)
{
	t_clean	t;

	t.j = 0;
	t.i = 0;
	t.q = 0;
	t.dq = 0;
	t.new = (char *)ft_memalloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	while (s[t.i])
	{
		s[t.i] == '"' && !(t.q % 2) ? t.dq++ : 0;
		s[t.i] == '\'' && !(t.dq % 2) ? t.q++ : 0;
		while ((s[t.i] == '"' && !(t.q % 2)) || (s[t.i] == '\'' && !(t.dq % 2)))
			t.i++;
		if (s[t.i] == -1)
			t.new[t.j] = ' ';
		else if (s[t.i] == -2)
			t.new[t.j] = '\t';
		else
			t.new[t.j] = (s[t.i] == -3) ? '\n' : s[t.i];
		t.i++;
		t.j++;
	}
	t.new[t.i] = 0;
	return (t.new);
}

void	remove_shit(char ***new)
{
	int			i;
	char		*tmp;

	i = 0;
	while ((*new)[i])
	{
		tmp = (*new)[i];
		(*new)[i] = ft_get_clean((*new)[i]);
		tmp ? free(tmp) : 0;
		i++;
	}
}
