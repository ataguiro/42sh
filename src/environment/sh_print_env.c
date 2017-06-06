/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <cjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:51:02 by cjacquem          #+#    #+#             */
/*   Updated: 2016/11/30 12:35:40 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "libft.h"

void		sh_print_env(t_variable *lst_env)
{
	while (lst_env)
	{
		ft_putendl(lst_env->variable);
		lst_env = lst_env->next;
	}
}
