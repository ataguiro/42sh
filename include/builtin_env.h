/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:46:12 by yfuks             #+#    #+#             */
/*   Updated: 2016/11/11 19:10:29 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_ENV_H
# define BUILTIN_ENV_H

# include <unistd.h>

# define SUCCESS		0
# define ERROR			1
# define CANNOTINVOKE	126
# define NOTFOUND		127

int		env_set_env(char *str, char ***env);
void	env_unset_env(void);
int		env_print_env(char **env);
int		env_execute_command(char **env, char **av, int index);
char	**env_alloc_env(size_t len);
int		env_parse_argv(int i, int ac, char **av, char ***env);
char	*env_get_env_key(char *str);
int		env_key_exist(char *key, char **env);
int		env_update_key(char *key, char *str, char **env);
int		env_add_key(char *str, char ***env);
int		env_get_env_size(char **env);
char	**env_copy_env(char **env);
void	env_free_env(char ***env);
int		env_is_executable(char *filepath);
char	*env_get_command_path(char **env, char *command_name);
char	*env_get_env_value(char *key, char **env);
void	env_put_error(char *executable, char *error);
int		env_is_option(char *str);
int		env_is_option_i(char *str);
int		env_is_option_u(char *str);
int		env_remove_key(int index, char **av, char ***env);
void	env_print_usage(void);
char	*env_get_paths(char **env);

#endif
