/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:48:08 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/07 12:56:50 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

# include "ft_printf.h"

# define SIZE_DYNAM 16
# define BUFF_SIZE 2056
# define ABS(x) x = x < 0 ? -x : x
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define COLOR_RESET "\x1b[0m"

/*
**	GNL.H
*/

# ifndef GNL_STRUCT
#  define GNL_STRUCT

typedef struct		s_gnl
{
	int				fd;
	char			*lfo;
}					t_gnl;

# endif

int					get_next_line(int const fd, char **line);
int					read_stdin(char **line);

/*
**	DYNAM.H
*/

typedef struct		s_dynam
{
	void			*data;
	size_t			t_size;
	size_t			max_elem;
	size_t			nb_elem;
}					t_dynam;

t_dynam				*ft_dynam_new(size_t type_size);
int					ft_dynam_append(t_dynam *dynam, void *new_data,\
						size_t nb_data);
int					ft_dynam_trim(t_dynam *dynam);
void				ft_dynam_destroy(t_dynam **dynam);

/*
**	BTREE.H
*/

typedef struct		s_btree
{
	void			*content;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

void				btree_apply_infix(t_btree *root, void (*applyf)(void*));
void				btree_apply_prefix(t_btree *root, void (*applyf)(void*));
void				btree_apply_suffix(t_btree *root, void (*applyf)(void*));
t_btree				*btree_create_node(void *item);
void				btree_insert_data(t_btree **root, void *item,\
						int (*cmpf)(void *, void *));
size_t				btree_level_count(t_btree *root);
void				*btree_search_item(t_btree *root, void *data_ref,\
						int (*cmpf)(void *, void *));

/*
**	LIST.H
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_lstlen(t_list *list);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

/*
**	PRINT FUNCTIONS
*/

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putstrcol(char const *s, char *color);
void				ft_putendl(char const *s);
void				ft_putendlcol(char const *s, char *color);
void				ft_putnbrendl(int n);
void				ft_putnbr(long long int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
**	CHAR FUNCTIONS
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isspace(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_iswhitespace(int c);
int					ft_isacharinstring(int c, const char *s);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
**	STRING FUNCTIONS
*/

int					ft_atoi(const char *str);
long				ft_atol(const char *str);
int					ft_atoi_base(const char *str, int base);
size_t				ft_count_words(const char *s, char c);
size_t				ft_strlen(char const *s);
void				ft_strupper(char *str);
int					ft_isstrdigit(char const *s);
int					ft_isstrempty(char const *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *src, size_t n);
char				*ft_strchange(char *in, const char *bywhat);
char				*ft_strinsert(char *str, char *to_insert, int where);
char				*ft_str3cat(char *s1, char *s2, char *s3);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strreplace(char *in, char *where, char *bywhat);
char				*ft_strdelchar(char *str, int index);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s);
char				*ft_trim_c(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

size_t				ft_wcslen(const wchar_t *wstr);
void				ft_exit(char *str);

/*
**	TAB FUNCTIONS
*/

size_t				ft_tablen(char **tab);
void				ft_tabfree(char ***tab);
int					*ft_tabatoi(char **tab);
void				ft_tabprint(char **tab);
char				**ft_tabndup(char **tab, int n);

/*
**	NB FUNCTIONS
*/

char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
size_t				ft_nbrlen(int n);
unsigned int		ft_power_pos(unsigned int n, unsigned int p);

/*
**	MEM FUNCTIONS
*/

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_realloc(void *ptr, size_t size);

#endif
