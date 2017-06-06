/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_read.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:01:19 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/15 15:49:07 by cjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_READ_H
# define BUILTIN_READ_H

# include <stddef.h>
# include <time.h>
# include "ft_42sh.h"

# define OPTION_D		(1 << 0)
# define OPTION_E		(1 << 1)
# define OPTION_N		(1 << 2)
# define OPTION_P		(1 << 3)
# define OPTION_R		(1 << 4)
# define OPTION_S		(1 << 5)
# define OPTION_T		(1 << 6)
# define OPTION_U		(1 << 7)

/*
**		-e : Write output in the terminal (Readline() ?)	OK
**		-r : backslash(\) do not escape characters			OK
**		-s : Dont echo input on terminal
**
**		-d : Delim = 1 char
**		-n : nchars -> 0 = infinite
**		-p : prompt											OK
**		-t : timeout										OK~
**		-u : read from given fd								OK
*/

typedef struct	s_read
{
	int		option;
	char	delim;
	size_t	nchars;
	char	*prompt;
	size_t	timeout;
	int		fd;
}				t_read;

int				read_get_options(char **av, t_read *tools);
int				read_option_error(char *str, char *msg);
int				read_input(t_read tools, char **line);
void			escape_line(char **line);
int				split_line_into_fields(t_shell *sh, char **av, char *line);
int				read_option_d(t_read *tools, char **av, int *i, int *j);
int				read_option_n(t_read *tools, char **av, int *i, int *j);
int				read_option_p(t_read *tools, char **av, int *i, int *j);
int				read_option_t(t_read *tools, char **av, int *i, int *j);
int				read_option_u(t_read *tools, char **av, int *i, int *j);

#endif
