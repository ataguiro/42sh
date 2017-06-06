/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:44:58 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/04 15:06:25 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static int	ft_isvalid(char c)
{
	if (ft_isprint(c) || (c == '\x9') || c == '\x4' || c == '\x7f' || c == '\xa'
	|| c == '\x1b' || c == '\x5b' || c == '\x41' || c == '\x42' || c == '\x43'
	|| c == '\x44' || c == '\x48' || c == '\x46' || c == '\x31' || c == '\x32'
	|| c == '\x3b' || c == '\x42' || c == '\x41' || c == '\x18' || c == '\x15'
	|| c == '\x17' || c == '\x0c' || c == '\x01' || c == '\x05' || c == '\x12')
		return (1);
	return (0);
}

void		key_dump(int key)
{
	(key == CODE_TAB) ? code_completion() : 0;
	(key == CODE_UP) ? code_up(key) : 0;
	(key == CODE_BACK) ? stremove() : 0;
	(key == CODE_RIGHT) ? code_right() : 0;
	(key == CODE_LEFT) ? code_left() : 0;
	(key == CODE_DOWN) ? code_down(key) : 0;
	(key == CODE_CTRL_D) ? code_ctrl_d() : 0;
	(key == CODE_RETURN) ? code_return(&key) : 0;
	(key == CODE_HOME) ? code_home() : 0;
	(key == CODE_END) ? code_end() : 0;
	(key == CODE_SHIFT_UP) ? code_shift_up() : 0;
	(key == CODE_SHIFT_DOWN) ? code_shift_down() : 0;
	(key == CODE_SHIFT_RIGHT) ? code_shift_right() : 0;
	(key == CODE_SHIFT_LEFT) ? code_shift_left() : 0;
	(key == CODE_CTRL_X) ? code_ctrl_x() : 0;
	(key == CODE_CTRL_U) ? code_ctrl_u() : 0;
	(key == CODE_CTRL_W) ? code_ctrl_w() : 0;
	(key == CODE_CTRL_L) ? code_ctrl_l() : 0;
	(key == CODE_CTRL_R) || *search_mode() ? code_ctrl_r() : 0;
}

int			key_get(void)
{
	char	c;

	raw_mode();
	read(0, &c, 1);
	if (!ft_isvalid(c))
		return (-3);
	if (c == '\x01')
		return (CODE_HOME);
	if (c == '\x05')
		return (CODE_END);
	if (c == '\x9' || c == '\x4' || c == '\x18' || c == '\x15' || c == '\x17' ||
	c == '\x7f' || c == '\xa' || c == '\x0c' || c == '\x12')
		return (get_basics(c));
	if (c == '\x1b')
	{
		read(0, &c, 1);
		return (get_x1b(c));
	}
	manage_command(c);
	return (-2);
}
