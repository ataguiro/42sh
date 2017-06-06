/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_history_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <cjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:48:57 by cjacquem          #+#    #+#             */
/*   Updated: 2017/01/18 21:23:37 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include "ft_42sh.h"
#include "history.h"
#include "libft.h"
#include "tools.h"

void			clear_history_list(void)
{
	t_list	*p;
	t_list	*elem;

	save_history_in_file(*get_new_list());
	p = *get_full_list();
	while (p)
	{
		elem = p;
		p = p->next;
		if (elem->content)
			ft_memdel((void*)&elem->content);
		ft_memdel((void*)&elem);
	}
	*get_full_list() = NULL;
	*get_new_list() = NULL;
}
