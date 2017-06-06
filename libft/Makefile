# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjacquem <cjacquem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:52:41 by cjacquem          #+#    #+#              #
#    Updated: 2016/12/09 17:22:45 by cjacquem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

CFLAGS = -c -Wall -Wextra -Werror

SRC_PATH = ./src/
SRC_NAME =	btree_apply_infix.c \
			ft_isdigit.c \
			ft_memdel.c \
			ft_strclr.c \
			ft_strnew.c \
			btree_apply_prefix.c \
			ft_isprint.c \
			ft_memmove.c \
			ft_strcmp.c \
			ft_strnstr.c \
			btree_apply_suffix.c \
			ft_isspace.c \
			ft_memset.c \
			ft_strcpy.c \
			ft_strrchr.c \
			btree_create_node.c \
			ft_isstrdigit.c \
			ft_nbrlen.c \
			ft_strdel.c \
			ft_strreplace.c \
			btree_insert_data.c \
			ft_isstrempty.c \
			ft_power_pos.c \
			ft_strdelchar.c \
			ft_strsplit.c \
			btree_level_count.c \
			ft_iswhitespace.c \
			ft_putchar.c \
			ft_strdup.c \
			ft_strstr.c \
			btree_search_data.c \
			ft_itoa_base.c \
			ft_putchar_fd.c \
			ft_strequ.c \
			ft_strsub.c \
			ft_atoi_base.c \
			ft_itoa.c \
			ft_putendl.c \
			ft_strinsert.c \
			ft_strtrim.c \
			ft_atoi.c \
			ft_lstadd.c \
			ft_putendlcol.c \
			ft_striter.c \
			ft_strupper.c \
			ft_atol.c \
			ft_lstaddend.c \
			ft_putendl_fd.c \
			ft_striteri.c \
			ft_tabatoi.c \
			ft_bzero.c \
			ft_lstdel.c \
			ft_putnbr.c \
			ft_strjoin.c \
			ft_tabfree.c \
			ft_count_words.c \
			ft_lstdelone.c \
			ft_putnbrendl.c \
			ft_strjoin_free.c \
			ft_tablen.c \
			ft_dynam_append.c \
			ft_lstiter.c \
			ft_putnbr_fd.c \
			ft_strlcat.c \
			ft_tabndup.c \
			ft_dynam_destroy.c \
			ft_lstlen.c \
			ft_putstr.c \
			ft_strlen.c \
			ft_tabprint.c \
			ft_dynam_new.c \
			ft_lstmap.c \
			ft_putstrcol.c \
			ft_strmap.c \
			ft_tolower.c \
			ft_dynam_trim.c \
			ft_lstnew.c \
			ft_putstr_fd.c \
			ft_strmapi.c \
			ft_toupper.c \
			ft_exit.c \
			ft_memalloc.c \
			ft_realloc.c \
			ft_strncat.c \
			ft_trim_c.c \
			ft_isacharinstring.c \
			ft_memccpy.c \
			ft_str3cat.c \
			ft_strncmp.c \
			ft_wcslen.c \
			ft_isalnum.c \
			ft_memchr.c \
			ft_strcat.c \
			ft_strncpy.c \
			get_next_line.c \
			ft_isalpha.c \
			ft_memcmp.c \
			ft_strchange.c \
			ft_strndup.c \
			read_stdin.c \
			ft_isascii.c \
			ft_memcpy.c \
			ft_strchr.c \
			ft_strnequ.c
SRC = $(addprefix $(SRC_PATH), $(SCR_NAME))

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:%.c=%.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INCLUDE_PATH = -I ./include/

.PHONY: clean fclean re all

all : $(NAME)

$(NAME): $(OBJ) $(SRC)
	@echo "\033[32m" "-> Libft" "\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(INCLUDE_PATH) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
