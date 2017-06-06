/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:49:07 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/25 12:25:56 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static void	single_line(int *q, int *dq, int *b, int i)
{
	while ((*command())[i])
	{
		if ((*command())[i] == '\\')
			(*b)++;
		else if (((*command())[i] != '"' && (*command())[i] != '\''
		&& (*command())[i] != '\n') || (*command())[i - 1] != '\\')
			*b = 0;
		if (*b == 2)
			*b = 0;
		if ((*command())[i] == '"' && !(*q % 2) && !(*b))
			(*dq)++;
		if ((*command())[i] == '\'' && !(*dq % 2) && (*q % 2 || !(*b)))
			(*q)++;
		if ((*command())[i] == '\'' || (*command())[i] == '"')
			*b = 0;
		if (!(*q % 2) && !(*dq % 2) && (*command())[i] == '(')
			(*lbracket())++;
		if (!(*q % 2) && !(*dq % 2) && (*command())[i] == ')')
			(*lbracket())--;
		i++;
	}
}

static void	multi_line(int *q, int *dq, int *b, int i)
{
	while ((*stock())[i])
	{
		if ((*stock())[i] == '\\')
			(*b)++;
		else if (((*stock())[i] != '"' && (*stock())[i] != '\''
		&& (*stock())[i] != '\n') || (*stock())[i - 1] != '\\')
			*b = 0;
		if (**command() == 0 || (*b == 2))
			*b = 0;
		if ((*stock())[i] == '"' && !(*q % 2) && !(*b))
			(*dq)++;
		if ((*stock())[i] == '\'' && !(*dq % 2) && (*q % 2 || !(*b)))
			(*q)++;
		if ((*stock())[i] == '\'' || (*stock())[i] == '"')
			*b = 0;
		if (!(*q % 2) && !(*dq % 2) && (*stock())[i] == '(')
			(*lbracket())++;
		if (!(*q % 2) && !(*dq % 2) && (*stock())[i] == ')')
			(*lbracket())--;
		i++;
	}
}

void		manage_quotes(void)
{
	int		i;
	int		dq;
	int		q;
	int		b;

	i = 0;
	q = 0;
	dq = 0;
	b = 0;
	*lbracket() = 0;
	if (*stock())
		multi_line(&q, &dq, &b, i);
	else
		single_line(&q, &dq, &b, i);
	if (ft_getlast(*command()) == '\'' || ft_getlast(*command()) == '"')
		b = 0;
	*(dquote()) = dq;
	*(quote()) = q;
	*(bs()) = b;
}

void		reset_quotes(void)
{
	*dquote() = 0;
	*quote() = 0;
	*bs() = 0;
	*lbracket() = 0;
}
