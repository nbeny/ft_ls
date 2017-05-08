/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:54:38 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/08 19:54:40 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static DIR				*ft_get_dir_norme(void)
{
	DIR	*dir;

	dir = opendir("/");
	if (dir == NULL)
	{
		perror("ls : No such file or directory\n");
		exit(EXIT_FAILURE);
	}
	return (dir);
}

static struct dirent	*ft_get_read_norme(DIR *dir)
{
	struct dirent	*d;

	d = readdir(dir);
	if (d == NULL)
	{
		perror("error ! Unable to read file.\n");
		exit(EXIT_FAILURE);
	}
	return (d);
}

t_elem					*ft_first_source(void)
{
	DIR				*dir;
	struct dirent	*d;
	struct stat		st;
	t_elem			*elem;

	dir = ft_get_dir_norme();
	d = ft_get_read_norme(dir);
	if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
	{
		perror("error ! Unable to malloc structure elem.\n");
		exit(EXIT_FAILURE);
	}
	elem->d_name = ft_strdup(d->d_name);
	if (lstat(elem->d_name, &st) == -1)
	{
		perror("error ! Unable to malloc structure elem.\n");
		exit(EXIT_FAILURE);
	}
	elem = ft_getstat(elem, elem->d_name);
	elem = ft_lstcpy_inelem(elem);
	closedir(dir);
	return (elem);
}

void					ft_free_arg(t_elem *elem)
{
	t_elem *save;

	while (elem != NULL)
	{
		if (S_ISLNK(elem->st_mode))
			ft_strdel(&(elem->lk_name));
		ft_strdel(&(elem->pw_name));
		ft_strdel(&(elem->gr_name));
		ft_strdel(&(elem->atime_c));
		ft_strdel(&(elem->mtime_c));
		save = elem;
		elem = elem->next;
		free(save);
		save = NULL;
	}
}

t_elem					*ft_free_firstone(t_elem *elem)
{
	t_elem	*sa;

	sa = elem;
	elem = elem->next;
	ft_strdel(&(sa->d_name));
	if (S_ISLNK(sa->st_mode))
		ft_strdel(&(sa->lk_name));
	ft_strdel(&(sa->pw_name));
	ft_strdel(&(sa->gr_name));
	ft_strdel(&(sa->atime_c));
	ft_strdel(&(sa->mtime_c));
	free(sa);
	sa = NULL;
	return (elem);
}
