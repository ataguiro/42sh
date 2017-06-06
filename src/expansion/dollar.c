/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <cjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:34:49 by cjacquem          #+#    #+#             */
/*   Updated: 2017/01/20 14:25:00 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "tools.h"

#define SPECIAL_VARIABLE "?$0"

static char	*build_key(char *p, int *variable_number)
{
	const char	special_variable[] = SPECIAL_VARIABLE;
	char		*key;
	int			i;
	size_t		len;

	key = NULL;
	len = 1;
	i = -1;
	while (special_variable[++i])
		if (special_variable[i] == p[1])
		{
			*variable_number = i;
			len++;
			break ;
		}
	if (len == 1)
	{
		i = 0;
		while (p[++i] && (ft_isalnum(p[i]) || p[i] == '_'))
			++len;
	}
	key = tl_strndup(p, len);
	return (key);
}

static char	*get_value(t_shell *sh, char *key, int variable_number)
{
	char		*value;

	value = NULL;
	if (variable_number == -1)
	{
		if (!(value = sh_getenv(sh->lst_localvar, key)))
			value = sh_getenv(sh->lst_env, key);
		value = ft_strdup(value);
	}
	else if (variable_number == 0)
		value = ft_itoa(sh->last_return);
	else if (variable_number == 1)
		value = ft_itoa(getpid());
	else if (variable_number == 2)
		value = ft_strdup("42sh");
	return (value);
}

char		*dollar(t_shell *sh, char *acmd, char *ptr)
{
	char		*key;
	char		*value;
	int			variable_number;

	variable_number = -1;
	if (!(key = build_key(ptr, &variable_number)))
		return (NULL);
	value = get_value(sh, key + 1, variable_number);
	acmd = tl_switch_string(acmd, (size_t)(ptr - acmd), value, key);
	ft_strdel(&key);
	ft_strdel(&value);
	return (acmd);
}
