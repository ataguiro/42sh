/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:44:31 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/09 16:35:16 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_env.h"
#include "libft.h"

static	int	env_is_namevalue(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	if (str[i] && str[i] == '=' && i > 0)
		return (1);
	return (0);
}

static	int	print_return_error(char *error, char *option)
{
	env_put_error(error, option);
	env_print_usage();
	return (ERROR);
}

int			env_parse_argv(int i, int ac, char **av, char ***env)
{
	i = 1;
	while (i < ac && env_is_option(av[i]))
	{
		if (env_is_option_i(av[i]))
			env_free_env(env);
		else if (env_is_option_u(av[i]))
		{
			if (env_remove_key(i + 1, av, env) == ERROR)
				return (ERROR);
			i++;
		}
		else
			return (print_return_error("illegal option", av[i]));
		i++;
	}
	while (i < ac)
	{
		if (env_is_namevalue(av[i]))
			env_set_env(av[i], env);
		else
			return (env_execute_command(*env, av, i));
		i++;
	}
	env_print_env(*env);
	return (0);
}
