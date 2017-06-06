/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:37:26 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/10 11:34:22 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include <stdlib.h>

# ifndef DEFAULT_PATH
#  define DEFAULT_PATH "/bin:/usr/bin"
# endif

typedef struct			s_variable
{
	char				*variable;
	size_t				length;
	struct s_variable	*next;
}						t_variable;

int						create_elem(t_variable **lst_env, char *variable);
void					clear_env_list(t_variable **lst_env);

size_t					lstvariable_len(t_variable *lstvariable);
char					**lstenv_to_tab(t_variable *lst_env);
char					*var_getkey(char *variable);

char					*sh_getenv(t_variable *lst_env, char *key);
int						sh_setenv(t_variable **lst_env, char *key, char *value);
int						sh_unsetenv(t_variable **lst_env, char *key);
void					sh_print_env(t_variable *lst_env);

#endif
