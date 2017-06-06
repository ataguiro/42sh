/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_position_offset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:00:05 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/18 20:00:57 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "input.h"
#include "builtin_history.h"

static int	error_out_of_range(int offset)
{
	ft_putstr_fd("42sh: history: ", 2);
	ft_putnbr_fd(offset, 2);
	ft_putstr_fd(": history position out of range\n", 2);
	return (1);
}

static void	del_element(t_list **prev, t_list **ptr)
{
	if (!*ptr)
		return ;
	if (*prev)
		(*prev)->next = (*ptr)->next;
	else
		*get_full_list() = (*ptr)->next;
	if (*ptr && (*ptr)->content)
		free((*ptr)->content);
	(*ptr)->content = NULL;
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

int			history_del_position_offset(t_list **lst,\
				t_hist_option tools, int offset)
{
	int		i;
	t_list	*ptr;
	t_list	*prev;

	i = 0;
	prev = NULL;
	ptr = *lst;
	while (ptr->next && i < offset)
	{
		i++;
		prev = ptr;
		ptr = ptr->next;
	}
	if (i != offset && tools.option & OPTION_D)
		return (error_out_of_range(offset));
	del_element(&prev, &ptr);
	return (0);
}
