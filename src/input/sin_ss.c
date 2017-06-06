/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sin_ss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:18:39 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/23 16:53:43 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	"(command)" --> OK
**	"(command)othercommand" --> ERROR
**	"command(othercommand)" --> ERROR
**	"()" --> ERROR
**	"(command); (othercommand)" --> OK (same with && and ||)
**	"(command; command)" --> OK (same with && and ||)
*/

int		*lbracket(void)
{
	static int	lbracket = 0;

	return (&lbracket);
}
