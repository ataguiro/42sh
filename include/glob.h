/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoac <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:58:56 by tpoac             #+#    #+#             */
/*   Updated: 2017/01/25 20:43:56 by tpoac            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_H
# define GLOB_H
# include "tools.h"
# include "libft.h"

int					matchpp(const char *s1, const char *s2);
t_list				*ft_glob(char *s);

#endif
