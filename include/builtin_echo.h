/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:20:19 by fhuang            #+#    #+#             */
/*   Updated: 2016/12/08 14:34:36 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_ECHO_H
# define BUILTIN_ECHO_H

typedef struct	s_escaped_char
{
	char		c;
	char		*escaped_char;
}				t_escaped_char;

int				echo_atoi_base(const char *str, int *ret,\
					int base, int nb_char);
int				echo_check_for_options(_Bool option[2], char *str);
int				echo_strings(_Bool option[2], char *str);
int				echo_is_ascii_char(char *str, int *i);

#endif
