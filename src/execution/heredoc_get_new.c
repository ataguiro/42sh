/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_get_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:59:33 by yfuks             #+#    #+#             */
/*   Updated: 2016/12/01 17:01:03 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

t_heredocs	*get_new_heredocs(t_list *words)
{
	t_heredocs	*doc;

	if (!(doc = (t_heredocs *)malloc(sizeof(t_heredocs))))
		return (0);
	doc->words = words;
	doc->next = 0;
	return (doc);
}
