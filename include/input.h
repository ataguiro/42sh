/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:18:09 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/03 14:15:00 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "ft_42sh.h"
# include "tools.h"

# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <dirent.h>
# include <termios.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ipc.h>

# define CODE_CTRL_D -1
# define CODE_RETURN 0
# define CODE_TAB 1
# define CODE_BACK 2
# define CODE_UP 10
# define CODE_DOWN 20
# define CODE_RIGHT 30
# define CODE_LEFT 40
# define CODE_HOME 107
# define CODE_END 2016
# define CODE_SHIFT_UP 41
# define CODE_SHIFT_DOWN 42
# define CODE_SHIFT_RIGHT 43
# define CODE_SHIFT_LEFT 44
# define CODE_CTRL_X 100
# define CODE_CTRL_U 200
# define CODE_CTRL_W 300
# define CODE_CTRL_L 400
# define CODE_CTRL_R 500

typedef	struct	s_infos2
{
	int				words;
	char			**new;
	char			*tmp;
	int				t;
	int				i;
}				t_infos2;

typedef struct	s_clean
{
	int				j;
	size_t			i;
	int				dq;
	int				q;
	char			*new;
}				t_clean;

typedef struct	s_termsize
{
	size_t			col;
	size_t			row;
}				t_termsize;

typedef struct	s_coord
{
	size_t			x;
	size_t			prompt_len;
	size_t			len;
}				t_coord;

typedef struct	s_comp
{
	char			*path;
	int				t;
	struct dirent	*lu;
	int				check;
	DIR				*dir;
	char			**splitted_path;
}				t_comp;

/*
**	COMPLETION
*/

t_list			**get_cursor_completion(void);
t_list			**get_list_completion(void);
void			clear_completion(void);
void			display_command(char **save, int pos);

int				is_delim_char(char *str, int i);
int				is_a_command(char *command);
int				look_for_a_file(char *command);
int				look_for_a_command(char *command);
int				search_through_dir(char *dir_name, char *command);

int				match(char *s1, char *s2);

/*
**	TOOLS
*/

void			init_input(void);

char			*newclean(char *str);
char			ft_getlast(char *str);
void			remove_shit(char ***new);
void			replace_with_shit(char **s);
char			**ft_strsplit_whitespace(char *s);
char			ft_getlast(char *str);
char			*strdup_input(char *src);

void			manage_command(char c);
void			stremove(void);
void			fill_space(int j);
void			strinsert_input(char c);

/*
**	KEY DUMP FUNCTIONS
*/

void			code_completion(void);
void			code_up(int key);
void			code_right(void);
void			code_left(void);
void			code_down(int key);
void			code_ctrl_d(void);
void			code_return(int *key);
void			code_home(void);
void			code_end(void);
void			code_shift_up(void);
void			code_shift_down(void);
void			code_shift_right(void);
void			code_shift_left(void);
void			code_ctrl_x(void);
void			code_ctrl_u(void);
void			code_ctrl_w(void);
void			code_ctrl_l(void);
void			code_ctrl_r(void);

/*
**	GET_KEY
*/

int				*prompt_len(void);
int				get_x31(char c);
int				get_x1b(char c);
int				get_basics(char c);

char			**found(void);
int				*search_mode(void);
int				*lbracket(void);
t_coord			*cor(void);
char			**stock(void);
char			**copied(void);
char			*newclean(char *str);
char			**command(void);
int				*dquote(void);
int				*quote(void);
int				*bs(void);
t_termsize		*termsize(void);
void			remove_display(char *to_add);
int				*pos(void);
int				*get_size(void);
char			*get_elem(int key);
void			in_history(char *buffer);
void			init_list(void);
void			fill_space(int j);
char			*ft_getenv(const char *need);
void			manage_quotes(void);
void			reset_quotes(void);
char			**old_command(void);

char			**ft_tabdup(char **tabl);
char			**ft_tabstr(char **tabl, char *str);
int				ft_tabreplace(char ***tabl, char *str, char *by);

int				input(void);
void			raw_mode(void);
void			default_mode(void);

int				key_get(void);
void			key_dump(int key);

void			move_left(int x);
void			move_right(int x);
void			move_down(int x);
void			move_up(int x);

#endif
