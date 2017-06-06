/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:35:18 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/17 13:29:08 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "ft_42sh.h"

# ifndef OLDPWD
#  define OLDPWD 0
# endif

# ifndef NEWPWD
#  define NEWPWD 1
# endif

# ifndef HOME
#  define HOME 2
# endif

typedef	struct	s_bnb
{
	char		*builtin;
	int			(*function)(t_shell *, int, char **);
}				t_bnb;

int				builtin_setenv(t_shell *sh, int ac, char **av);
int				builtin_unsetenv(t_shell *sh, int ac, char **av);
int				builtin_exit(t_shell *sh, int ac, char **av);
int				builtin_read(t_shell *sh, int ac, char **av);
int				builtin_unset(t_shell *sh, int ac, char **av);
int				builtin_unalias(t_shell *sh, int ac, char **av);
int				builtin_history(t_shell *sh, int ac, char **av);

/*
**				CD
*/
int				builtin_cd(t_shell *sh, int ac, char **av);
int				change_directory(t_variable **lst_env, char *path, \
					_Bool follow_sl);
_Bool			get_options(char **av, int *i);
int				cd_error(int index, char *path);

/*
**				EXPORT
*/
int				builtin_export(t_shell *sh, int ac, char **av);
char			**create_variables_tab(t_variable *lst_env,\
												t_variable *lst_localvar);
void			print_export(t_variable *lst_env, t_variable *lst_localvar);

/*
**				ALIAS
*/
int				builtin_alias(t_shell *sh, int ac, char **av);
void			print_alias(t_variable *lst_alias);

#endif
