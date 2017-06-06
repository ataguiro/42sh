/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_completion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 22:11:47 by fhuang            #+#    #+#             */
/*   Updated: 2017/01/24 22:16:32 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	clear_completion(void)
{
	*get_cursor_completion() = NULL;
	tl_lstfree(get_list_completion());
}
