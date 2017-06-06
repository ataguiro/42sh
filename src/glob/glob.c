/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoac <tpoac@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:58:56 by tpoac             #+#    #+#             */
/*   Updated: 2017/02/05 16:41:58 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

static char			*handle_dir(char *s, DIR **current_dir)
{
	char			*dir;
	size_t			end;

	dir = ".";
	if (ft_strchr(s, '/'))
	{
		end = (size_t)tl_strnupto(s, "/", tl_strcntc(s, "/") - 1);
		dir = ft_strsub(s, 0, end);
	}
	if (!(*current_dir = opendir(dir)))
	{
		if (!ft_strequ(dir, "."))
			free(dir);
		return (NULL);
	}
	return (dir);
}

static void			ft_glob_files(
					char *s,
					char *d_name,
					t_list **files,
					char *change_dir)
{
	t_list			*new;
	char			*tmp;
	size_t			begin;

	begin = (size_t)tl_strnupto(s, "/", tl_strcntc(s, "/") - 1);
	if (d_name[0] != '.' && matchpp(d_name, &s[begin]))
	{
		new = ft_lstnew(d_name, ft_strlen(d_name) + 1);
		if (!ft_strequ(change_dir, "."))
		{
			tmp = new->content;
			new->content = ft_strjoin(change_dir, new->content);
			free(tmp);
		}
		ft_lstaddend(files, new);
	}
}

t_list				*ft_glob(char *s)
{
	DIR				*current_dir;
	struct dirent	*dir;
	t_list			*files;
	char			*change_dir;

	if (!s)
		return (NULL);
	dir = NULL;
	files = NULL;
	current_dir = NULL;
	if (!(change_dir = handle_dir(s, &current_dir)))
		return (NULL);
	while (current_dir && (dir = readdir(current_dir)) != NULL)
		ft_glob_files(s, dir->d_name, &files, change_dir);
	if (!ft_strequ(change_dir, "."))
		free(change_dir);
	closedir(current_dir);
	if (!files)
		files = ft_lstnew(s, ft_strlen(s) + 1);
	return (files);
}
