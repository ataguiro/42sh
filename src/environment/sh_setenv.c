/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:36:34 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/08 15:59:35 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "tools.h"
#include "libft.h"
#include "ft_42sh.h"

/*
**		This function adds the variable name to the
**			environment list with the given value.
**		If key does exist in the environment, then its value is changed,
**		if length if big enough, the string is not reallocated;
**		Else key and value are added at the end of the list.
*/

static int	switch_value(t_variable **elem, char *key, char *value)
{
	int			len;

	if ((len = ft_strlen(key) + ft_strlen(value) + 1 > (*elem)->length))
	{
		ft_strdel(&(*elem)->variable);
		if (!((*elem)->variable = tl_str3join(key, "=", value)))
			return (ERROR);
		(*elem)->length = len;
	}
	else
	{
		ft_strclr((*elem)->variable + ft_strlen(key) + 1);
		(*elem)->variable = ft_strcat((*elem)->variable, value);
	}
	return (GOOD);
}

static int	add_value(t_variable **lst_env, char *key, char *value)
{
	char		*variable;

	if (!(variable = tl_str3join(key, "=", value)))
		return (ERROR);
	if (!create_elem(lst_env, variable))
	{
		ft_strdel(&variable);
		return (ERROR);
	}
	ft_strdel(&variable);
	return (GOOD);
}

int			sh_setenv(t_variable **lst_env, char *key, char *value)
{
	t_variable	*elem;
	char		*tmp;
	int			ret;

	elem = *lst_env;
	while (elem && key)
	{
		if ((tmp = tl_strndup(elem->variable,\
			(size_t)(ft_strchr(elem->variable, '=') - elem->variable))))
		{
			if (ft_strequ(key, tmp))
			{
				ret = switch_value(&elem, key, value);
				ft_strdel(&tmp);
				return (ret);
			}
			ft_strdel(&tmp);
		}
		elem = elem->next;
	}
	return (add_value(lst_env, key, value));
}
