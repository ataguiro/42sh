/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:07:36 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/05 14:05:36 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_H
# define FT_42SH_H

/*
**	LIBRAIRIES
*/

# include <termios.h>
# include "libft.h"
# include "environment.h"
# include "history.h"

/*
**	STANDARD LIRAIRIES STRUCTURES
*/

typedef struct dirent	t_dirent;
/*
**	ino_t          d_ino;		* numéro d'inœud *
**	off_t          d_off;		* décalage jusqu'à la dirent suivante *
**	unsigned short d_reclen;	* longueur de cet enregistrement *
**	unsigned char  d_type;		* type du fichier *
**	char           d_name[256];	* nom du fichier *
*/

typedef struct stat		t_stat;
/*
**	dev_t     st_dev;			* ID du périphérique contenant le fichier *
**	ino_t     st_ino;			* Numéro inœud *
**	mode_t    st_mode;			* Protection *
**	nlink_t   st_nlink;			* Nb liens matériels *
**	uid_t     st_uid;			* UID propriétaire *
**	gid_t     st_gid;			* GID propriétaire *
**	dev_t     st_rdev;			* ID périphérique (si fichier spécial) *
**	off_t     st_size;			* Taille totale en octets *
**	blksize_t st_blksize;		* Taille de bloc pour E/S *
**	blkcnt_t  st_blocks;		* Nombre de blocs alloués *
**	time_t    st_atime;			* Heure dernier accès *
**	time_t    st_mtime;			* Heure dernière modification *
**	time_t    st_ctime;			* Heure dernier changement état *
*/

typedef struct termios	t_termios;
/*
**	tcflag_t	c_iflag;		* modes d'entrée *
**	tcflag_t	c_oflag;		* modes de sortie *
**	tcflag_t	c_cflag;		* modes de contrôle *
**	tcflag_t	c_lflag;		* modes locaux *
**	cc_t		c_cc[NCCS];		* caractères de contrôle *
*/

typedef struct winsize	t_winsize;
/*
**	unsigned short	ws_row;
**	unsigned short	ws_col;
**	unsigned short	ws_xpixel;
**	unsigned short	ws_ypixel;
*/

/*
**	RETURN VALUES
*/
# ifndef ERROR
#  define ERROR 0
# endif

# ifndef GOOD
#  define GOOD 1
# endif

/*
**	SHELL STRUCTURE AND DEFINES
*/

typedef struct			s_shell
{
	int					last_return;
	t_variable			*lst_env;
	t_variable			*lst_localvar;
	t_variable			*lst_alias;
	char				*bin_path;
	t_termios			term;
	t_winsize			*window;
}						t_shell;

typedef struct			s_bitfield
{
	unsigned int		squote : 1;
	unsigned int		dquote : 1;
	unsigned int		bslash : 1;
}						t_bitfield;

# ifndef BUFF_SIZE
#  define BUFF_SIZE 256
# endif

# ifndef NONEWLINE
#  define NONEWLINE "\033[7m%\033[m\n"
# endif

/*
**	BUILTIN CODE
*/

# ifndef BUILTIN
#  define _BUILTIN1 "cd exit read unsetenv setenv export unset"
#  define _BUILTIN2 " alias unalias history"
#  define _BINARY_BUILTIN " echo env"
#  define BUILTIN _BUILTIN1 _BUILTIN2
# endif

# ifndef NBBUILTIN
#  define NBBUILTIN 6
# endif

/*
**	SHELL ENVIRONMENT
*/

char					**user(void);
char					**get_home(void);

/*
**	SHELL BASIC FUNCTIONS
*/

int						import_shrc(t_shell *sh);
int						init_shell(t_shell *sh, char *av_0);
void					clear_shell(t_shell *sh);

int						prompt(void);
int						get_line(int fd, char **line);
void					sig_handler(int signo);
void					loop_through_commands(t_shell *sh,\
							t_list *lst_commands);

int						pipe_command(void);
int						get_heredocs(t_shell *sh, t_list **lst);
int						exec_command(t_shell *sh, char **command);
int						lexer_parser(char **command_line, t_list **lst);

#endif
