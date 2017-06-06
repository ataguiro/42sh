# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjacquem <cjacquem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/15 14:57:28 by cjacquem          #+#    #+#              #
#    Updated: 2017/02/05 17:32:33 by cjacquem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Editable =====
NAME	:=	42sh
# ====================

# ===== Standard =====
CC		:=	clang -pipe
CFLAGS	:=	-Wall -Wextra -Werror -g3
SRCDIR	:=	src/
OBJDIR	:=	obj/
BINDIR	:=	bin/
INCDIR	:=	include/
LIBDIR	:=	libft/
DIRBUILTINS	:= obj/builtins/
SRC		:=	$(SRCDIR)ast/ast_create_elem.c \
			$(SRCDIR)ast/ast_create_tree.c \
			$(SRCDIR)ast/ast_destroy_tree.c \
			$(SRCDIR)ast/ast_free_cmdwr.c \
			$(SRCDIR)ast/ast_insert_elem_in_tree.c \
			$(SRCDIR)ast/ast_parse_tree.c \
			$(SRCDIR)ast/ast_to_cmdwr.c \
			$(SRCDIR)ast/ast_to_lst.c \
			$(SRCDIR)ast/cmdwr_check_redirections.c \
			$(SRCDIR)ast/cmdwr_fill_struct.c \
			$(SRCDIR)ast/line_to_ast.c \
			$(SRCDIR)ast/redirection_create_elem.c \
			$(SRCDIR)ast/ast_special_is_space.c \
			$(SRCDIR)ast/ast_special_trim.c \
			$(SRCDIR)builtins/alias/builtin_alias.c \
			$(SRCDIR)builtins/alias/print_alias.c \
			$(SRCDIR)builtins/cd/builtin_cd.c \
			$(SRCDIR)builtins/cd/cd_error.c \
			$(SRCDIR)builtins/cd/change_directory.c \
			$(SRCDIR)builtins/cd/get_options.c \
			$(SRCDIR)builtins/exit/builtin_exit.c \
			$(SRCDIR)builtins/export/builtin_export.c \
			$(SRCDIR)builtins/export/create_variables_tab.c \
			$(SRCDIR)builtins/export/print_export.c \
			$(SRCDIR)builtins/read/escape_line.c \
			$(SRCDIR)builtins/read/get_options.c \
			$(SRCDIR)builtins/read/builtin_read.c \
			$(SRCDIR)builtins/read/option_d.c \
			$(SRCDIR)builtins/read/option_error.c \
			$(SRCDIR)builtins/read/option_n.c \
			$(SRCDIR)builtins/read/option_p.c \
			$(SRCDIR)builtins/read/option_t.c \
			$(SRCDIR)builtins/read/option_u.c \
			$(SRCDIR)builtins/read/read_input.c \
			$(SRCDIR)builtins/read/split_line_into_fields.c \
			$(SRCDIR)builtins/setenv/builtin_setenv.c \
			$(SRCDIR)builtins/unalias/builtin_unalias.c \
			$(SRCDIR)builtins/unset/builtin_unset.c \
			$(SRCDIR)builtins/unsetenv/builtin_unsetenv.c \
			$(SRCDIR)builtins/history/append_file_to_list.c \
			$(SRCDIR)builtins/history/builtin_history.c \
			$(SRCDIR)builtins/history/clear_list.c \
			$(SRCDIR)builtins/history/del_position_offset.c \
			$(SRCDIR)builtins/history/get_options.c \
			$(SRCDIR)builtins/history/print_list.c \
			$(SRCDIR)builtins/history/option_s.c \
			$(SRCDIR)builtins/history/option_p.c \
			$(SRCDIR)builtins/history/overwrite_history_file.c \
			$(SRCDIR)clear_shell.c \
			$(SRCDIR)environment/clear_env_list.c \
			$(SRCDIR)environment/create_elem.c \
			$(SRCDIR)environment/lstenv_to_tab.c \
			$(SRCDIR)environment/lstvariable_len.c \
			$(SRCDIR)environment/sh_getenv.c \
			$(SRCDIR)environment/sh_print_env.c \
			$(SRCDIR)environment/sh_setenv.c \
			$(SRCDIR)environment/sh_unsetenv.c \
			$(SRCDIR)environment/var_getkey.c \
			$(SRCDIR)exec_ast.c \
			$(SRCDIR)exec_command.c \
			$(SRCDIR)execution/exec_closes_and_redirects.c \
			$(SRCDIR)execution/exec_execute_command.c \
			$(SRCDIR)execution/exec_get_command_status_code.c \
			$(SRCDIR)execution/exec_get_envpath.c \
			$(SRCDIR)execution/exec_is_builtin.c \
			$(SRCDIR)execution/exec_is_command.c \
			$(SRCDIR)execution/exec_is_directory.c \
			$(SRCDIR)execution/exec_is_executable.c \
			$(SRCDIR)execution/exec_is_file.c \
			$(SRCDIR)execution/exec_is_readable.c \
			$(SRCDIR)execution/exec_is_standalone.c \
			$(SRCDIR)execution/exec_is_writable.c \
			$(SRCDIR)execution/exec_pipe.c \
			$(SRCDIR)execution/exec_print_command_error.c \
			$(SRCDIR)execution/exec_redirection.c \
			$(SRCDIR)execution/heredoc_free_heredocs.c \
			$(SRCDIR)execution/heredoc_get_heredoc.c \
			$(SRCDIR)execution/heredoc_get_new.c \
			$(SRCDIR)execution/heredoc_prompt.c \
			$(SRCDIR)expansion/alias_substitution.c \
			$(SRCDIR)expansion/dollar.c \
			$(SRCDIR)expansion/glob_substitution.c \
			$(SRCDIR)expansion/exclamation_mark.c \
			$(SRCDIR)expansion/quotes.c \
			$(SRCDIR)expansion/substitute.c \
			$(SRCDIR)expansion/tilde.c \
			$(SRCDIR)get_heredocs.c \
			$(SRCDIR)get_home.c \
			$(SRCDIR)get_line.c \
			$(SRCDIR)get_user.c \
			$(SRCDIR)history/clear_history_list.c \
			$(SRCDIR)history/delete_last_entry.c \
			$(SRCDIR)history/get_history_list.c \
			$(SRCDIR)history/init_history_list.c \
			$(SRCDIR)history/save_history_in_file.c \
			$(SRCDIR)history/save_command_line.c \
			$(SRCDIR)import_shrc.c \
			$(SRCDIR)init_shell.c \
			$(SRCDIR)input/code_completion.c \
			$(SRCDIR)input/code_ctrl_d.c \
			$(SRCDIR)input/code_ctrl_l.c \
			$(SRCDIR)input/code_ctrl_u.c \
			$(SRCDIR)input/code_ctrl_w.c \
			$(SRCDIR)input/code_ctrl_x.c \
			$(SRCDIR)input/code_ctrl_r.c \
			$(SRCDIR)input/code_down.c \
			$(SRCDIR)input/code_end.c \
			$(SRCDIR)input/code_home.c \
			$(SRCDIR)input/code_left.c \
			$(SRCDIR)input/code_return.c \
			$(SRCDIR)input/code_right.c \
			$(SRCDIR)input/code_shift_down.c \
			$(SRCDIR)input/code_shift_left.c \
			$(SRCDIR)input/code_shift_right.c \
			$(SRCDIR)input/code_shift_up.c \
			$(SRCDIR)input/code_up.c \
			$(SRCDIR)input/command.c \
			$(SRCDIR)input/completion/clear_completion.c \
			$(SRCDIR)input/completion/display_command.c \
			$(SRCDIR)input/completion/get_completion_list.c \
			$(SRCDIR)input/completion/is_a_command.c \
			$(SRCDIR)input/completion/is_delim_char.c \
			$(SRCDIR)input/completion/look_for_a_command.c \
			$(SRCDIR)input/completion/look_for_a_file.c \
			$(SRCDIR)input/completion/search_through_dir.c \
			$(SRCDIR)input/ft_getlast.c \
			$(SRCDIR)input/ft_strsplit_whitespace.c \
			$(SRCDIR)input/ft_tabdup.c \
			$(SRCDIR)input/ft_tabreplace.c \
			$(SRCDIR)input/ft_tabstr.c \
			$(SRCDIR)input/history_get_elem.c \
			$(SRCDIR)input/init_input.c \
			$(SRCDIR)input/input.c \
			$(SRCDIR)input/key.c \
			$(SRCDIR)input/key_get.c \
			$(SRCDIR)input/match.c \
			$(SRCDIR)input/modes.c \
			$(SRCDIR)input/move.c \
			$(SRCDIR)input/quotes.c \
			$(SRCDIR)input/remove_display.c \
			$(SRCDIR)input/remove_shit.c \
			$(SRCDIR)input/replace_with_shit.c \
			$(SRCDIR)input/sin_env.c \
			$(SRCDIR)input/sin_input.c \
			$(SRCDIR)input/sin_list.c \
			$(SRCDIR)input/sin_quotes.c \
			$(SRCDIR)input/sin_ss.c \
			$(SRCDIR)input/strdup_input.c \
			$(SRCDIR)lexer_parser.c \
			$(SRCDIR)loop_through_commands.c \
			$(SRCDIR)main.c \
			$(SRCDIR)prompt.c \
			$(SRCDIR)sig_handler.c \
			$(SRCDIR)tools/tl_strupto.c \
			$(SRCDIR)tools/tl_cis.c \
			$(SRCDIR)tools/tl_arrlen.c \
			$(SRCDIR)tools/tl_atoll.c \
			$(SRCDIR)tools/tl_closedir.c \
			$(SRCDIR)tools/tl_del.c \
			$(SRCDIR)tools/tl_freedoubletab.c \
			$(SRCDIR)tools/tl_get_next_line.c \
			$(SRCDIR)tools/tl_is_a_directory.c \
			$(SRCDIR)tools/tl_isstrdigit.c \
			$(SRCDIR)tools/tl_isstreempty.c \
			$(SRCDIR)tools/tl_iswhitespace.c \
			$(SRCDIR)tools/tl_jump_to_other_quote.c \
			$(SRCDIR)tools/tl_tabtolst.c \
			$(SRCDIR)tools/tl_lstadd_sortalpha.c \
			$(SRCDIR)tools/tl_lstaddend.c \
			$(SRCDIR)tools/tl_lstdelast.c \
			$(SRCDIR)tools/tl_lstfree.c \
			$(SRCDIR)tools/tl_nodefree.c \
			$(SRCDIR)tools/tl_lstlast.c \
			$(SRCDIR)tools/tl_lstnew.c \
			$(SRCDIR)tools/tl_opendir.c \
			$(SRCDIR)tools/tl_str3join.c \
			$(SRCDIR)tools/tl_strisalnum.c \
			$(SRCDIR)tools/tl_strmerge.c \
			$(SRCDIR)tools/tl_strndup.c \
			$(SRCDIR)tools/tl_strrealloc.c \
			$(SRCDIR)tools/tl_lsttotab.c \
			$(SRCDIR)tools/tl_lstnewstr.c \
			$(SRCDIR)tools/tl_memdup.c \
			$(SRCDIR)tools/tl_strnupto.c \
			$(SRCDIR)tools/tl_strcntc.c \
			$(SRCDIR)tools/tl_strcpy_w_blank.c \
			$(SRCDIR)glob/matchpp.c \
			$(SRCDIR)glob/glob.c \
			$(SRCDIR)tools/tl_switch_string.c
OBJ		:=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
INC		:=	-I./$(INCDIR) -I./$(LIBDIR)$(INCDIR)
LIBPATH	:=	-L./$(LIBDIR) -lft
CACHEF	:=	.cache_exists
HISTORY	:=	~/.42sh_history
42SHRC	:=	~/.42shrc
# ====================

# ====== Colors ======
CLEAR		= "\033[2K"
UP			= "\033[A"
EOC			= "\033[0;0m"
BLACK		= "\033[0;30m"
RED			= "\033[0;31m"
GREEN		= "\033[0;32m"
YELLOW		= "\033[0;33m"
BLUE		= "\033[0;34m"
PURPLE		= "\033[0;35m"
CYAN		= "\033[0;36m"
WHITE		= "\033[0;37m"
# ====================

# ===== env =====
DIRENV	:=	$(SRCDIR)builtins/env/
OBJDIRENV	:= $(DIRBUILTINS)env/
BINENV	:=	$(BINDIR)env
SRCENV	:=	$(DIRENV)add_key.c \
			$(DIRENV)alloc_env.c \
			$(DIRENV)copy_env.c \
			$(DIRENV)exec_command.c \
			$(DIRENV)free_env.c \
			$(DIRENV)get_command_path.c \
			$(DIRENV)get_env_key.c \
			$(DIRENV)get_env_size.c \
			$(DIRENV)get_env_value.c \
			$(DIRENV)get_paths.c \
			$(DIRENV)is_executable.c \
			$(DIRENV)is_option.c \
			$(DIRENV)is_option_i.c \
			$(DIRENV)is_option_u.c \
			$(DIRENV)key_exist.c \
			$(DIRENV)main.c \
			$(DIRENV)parse_argv.c \
			$(DIRENV)print_env.c \
			$(DIRENV)print_usage.c \
			$(DIRENV)put_error.c \
			$(DIRENV)remove_key.c \
			$(DIRENV)set_env.c \
			$(DIRENV)update_key.c
OBJENV	:=	$(SRCENV:$(DIRENV)%.c=$(OBJDIRENV)%.o)
# ===============

# ===== echo =====
DIRECHO	:=	$(SRCDIR)builtins/echo/
OBJDIRECHO	:= $(DIRBUILTINS)echo/
BINECHO	:=	$(BINDIR)echo
SRCECHO	:=	$(DIRECHO)check_for_options.c \
			$(DIRECHO)echo_atoi_base.c \
			$(DIRECHO)echo_strings.c \
			$(DIRECHO)is_ascii_char.c \
			$(DIRECHO)main.c
OBJECHO	:=	$(SRCECHO:$(DIRECHO)%.c=$(OBJDIRECHO)%.o)
# ================

.PHONY: all libft echo env norme clean fclean re
.SILENT:

all: $(NAME)
	echo "alias l='ls -lG'\\n" > $(42SHRC)

$(NAME): libft env echo $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBPATH) $(LIB) $(INC)
	printf $(GREEN)" $@ compiled!\n"$(EOC)

$(OBJDIR)%.o: $(SRCDIR)%.c $(CACHEF)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	printf $(GREEN)"|"$(EOC)

$(CACHEF):
	test -d $(OBJDIR) || mkdir $(OBJDIR)
	test -d $(DIRBUILTINS) || mkdir $(DIRBUILTINS)
	test -d $(DIRBUILTINS)alias || mkdir $(DIRBUILTINS)alias
	test -d $(DIRBUILTINS)unalias || mkdir $(DIRBUILTINS)unalias
	test -d $(DIRBUILTINS)cd || mkdir $(DIRBUILTINS)cd
	test -d $(DIRBUILTINS)read || mkdir $(DIRBUILTINS)read
	test -d $(DIRBUILTINS)setenv || mkdir $(DIRBUILTINS)setenv
	test -d $(DIRBUILTINS)unsetenv || mkdir $(DIRBUILTINS)unsetenv
	test -d $(DIRBUILTINS)exit || mkdir $(DIRBUILTINS)exit
	test -d $(DIRBUILTINS)export || mkdir $(DIRBUILTINS)export
	test -d $(DIRBUILTINS)unset || mkdir $(DIRBUILTINS)unset
	test -d $(DIRBUILTINS)history || mkdir $(DIRBUILTINS)history
	test -d $(OBJDIRENV) || mkdir $(OBJDIRENV)
	test -d $(OBJDIRECHO) || mkdir $(OBJDIRECHO)
	test -d $(OBJDIR)environment || mkdir $(OBJDIR)environment
	test -d $(OBJDIR)expansion || mkdir $(OBJDIR)expansion
	test -d $(OBJDIR)ast || mkdir $(OBJDIR)ast
	test -d $(OBJDIR)tools || mkdir $(OBJDIR)tools
	test -d $(OBJDIR)glob || mkdir $(OBJDIR)glob
	test -d $(OBJDIR)execution || mkdir $(OBJDIR)execution
	test -d $(OBJDIR)history || mkdir $(OBJDIR)history
	test -d $(OBJDIR)input || mkdir $(OBJDIR)input
	test -d $(OBJDIR)input/completion || mkdir $(OBJDIR)input/completion
	test -d $(BINDIR) || mkdir $(BINDIR)
	test -d $(CACHEF) || touch $(CACHEF)

%.c:
	printf $(RED)"Missing file : $@\n"$(EOC)

libft:
	make -C $(LIBDIR)

echo: $(OBJECHO)
	$(CC) $(CFLAGS) -o $(BINECHO) $(OBJECHO) $(LIBPATH) $(LIB) $(INC)
	printf $(GREEN)" $@ compiled!\n"$(EOC)

env: $(OBJENV)
	$(CC) $(CFLAGS) -o $(BINENV) $(OBJENV) $(LIBPATH) $(LIB) $(INC)
	printf $(GREEN)" $@ compiled!\n"$(EOC)

norme:
	norminette $(SRCDIR) $(INCDIR) | grep -v Norme -B1 || true
	norminette $(LIBFT)$(SRCDIR) $(LIBFT)$(INCDIR) | grep -v Norme -B1 || true

clean:
	make -C $(LIBDIR) clean
	rm -rf $(OBJDIR) $(CACHEF)
	printf $(YELLOW)"All objects removed\n"$(EOC)

fclean: clean
	make -C $(LIBDIR) fclean
	test -d $(HISTORY) | rm -f $(HISTORY)
	test -d $(42SHRC) | rm -f $(42SHRC)
	rm -f $(NAME)
	rm -rf $(BINDIR)
	printf $(RED)"$(NAME) removed\n"$(EOC)

re: fclean all
