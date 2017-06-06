/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:14:50 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/18 21:36:15 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"
#include "tools.h"

static void	do_padding(int padding, int nb)
{
	int		i;

	ft_putstr("   ");
	i = padding - ft_nbrlen(nb);
	while (i > 0)
	{
		ft_putstr(" ");
		--i;
	}
}

static int	check_arguments(char **av)
{
	if (!tl_isstrdigit(av[0]))
	{
		ft_putstr_fd("42sh: history: ", 2);
		ft_putstr_fd(av[0], 2);
		ft_putstr_fd(": numeric argument required\ns", 2);
		return (ERROR);
	}
	if (tl_arrlen(av) > 1)
	{
		ft_putstr_fd("42sh: history: too many arguments\n", 2);
		return (ERROR);
	}
	return (GOOD);
}

static void	display_history_list(t_list *lst, int i, int size)
{
	int		padding;

	padding = ft_nbrlen(size);
	while (lst)
	{
		if (lst->content)
		{
			do_padding(padding, i);
			ft_putnbr(i++);
			ft_putstr("  ");
			ft_putendl(lst->content);
		}
		lst = lst->next;
	}
}

int			history_print_list(t_list *lst, char **av)
{
	int		size;
	int		i;
	int		start;

	if (av && av[0] && !check_arguments(av))
		return (1);
	i = 0;
	size = ft_lstlen(lst);
	start = av && av[0] ? size - ft_atoi(av[0]) : 1;
	while (i < (start > 0 ? start : 1))
	{
		lst = lst->next;
		++i;
	}
	display_history_list(lst, i, size);
	return (0);
}
