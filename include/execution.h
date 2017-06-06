/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:09:11 by yfuks             #+#    #+#             */
/*   Updated: 2017/02/01 15:58:50 by tpoac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# define NOSUCHFILE			1
# define PERMISSIONDENIED	2
# define BADFILEDESCRIPTOR	3
# define ISDIRECTORY		125
# define CANNOTINVOKE		126
# define NOTFOUND			127
# define TOOLONG			128

# include "ft_42sh.h"
# include "environment.h"

/*
**	ex:
**	echo coucou >&-
**	echo coucou >& -
**	cat 1<&-
*/

# define CLOSE_REDIRECT			(1 << 0)

/*
**	">"
*/
# define SIMPLE_RIGHT_REDIRECT	(1 << 1)

/*
**	"<"
*/
# define SIMPLE_LEFT_REDIRECT	(1 << 2)

/*
**	">>"
*/
# define DOUBLE_RIGHT_REDIRECT	(1 << 3)

/*
**	"<<"
*/
# define DOUBLE_LEFT_REDIRECT	(1 << 4)

/*
**	"< file"
**	"1< file"
**	"2> file"
*/
# define FILE_REDIRECT			(1 << 5)

typedef struct	s_exec
{
	char					*command;
	int						builtin_not_binary;
}				t_exec;

typedef	struct	s_redirections
{
	int						from_fd;
	int						to_fd;
	char					*dest;
	int						type;
	struct s_redirections	*next;
}				t_redirections;

typedef struct	s_heredocs
{
	t_list					*words;
	struct s_heredocs		*next;
}				t_heredocs;

typedef struct	s_cmdwr
{
	char					**command;
	t_redirections			*redirs;
	t_heredocs				*heredocs;
}				t_cmdwr;

typedef struct	s_pipe
{
	t_list		*begin;
	pid_t		id;
	int			pipefd[2];
}				t_pipe;

int				exec_is_executable(char *filepath);
char			**exec_get_envpath(t_shell *sh);
int				exec_is_command(t_exec *ex, t_shell *sh, char **command,\
					char **path);
int				exec_is_builtin(t_exec *ex, t_shell *sh, char **command);
int				exec_is_standalone(t_exec *ex, char **command, char **paths);
int				exec_is_file(char *filepath);
int				exec_is_directory(char *filepath);
int				exec_is_readable(char *filepath);
int				exec_is_writable(char *filepath);
int				exec_execute_command(t_exec *ex, t_shell *sh, char **command);
int				exec_print_command_error(int error, char *command_name);
int				get_command_status_code(int status);
int				exec_redirection(t_shell *sh, t_cmdwr *r);
void			close_and_redirects(t_cmdwr *cmd, t_redirections **cursor);

t_heredocs		*get_new_heredocs(t_list *words);
int				heredoc_prompt(void);
void			get_heredoc(t_shell *sh, t_cmdwr *cmd, t_redirections *r);
void			free_heredocs(t_cmdwr *cmd);

#endif
