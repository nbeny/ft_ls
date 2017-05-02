/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 01:44:21 by nbeny             #+#    #+#             */
/*   Updated: 2017/04/12 01:44:26 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_elem	*ft_lstcpy_inelem(t_elem *elem)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(elem->st_uid);
	if (pwd == NULL)
	{
		perror("error ! Unable to malloc structure pwd.\n");
		exit(EXIT_FAILURE);
	}
	grp = getgrgid(elem->st_gid);
	if(grp == NULL)
	{
		perror("error ! Unable to malloc structure grp.\n");
		exit(EXIT_FAILURE);
	}
	elem->pw_name = ft_strdup(pwd->pw_name);
	elem->gr_name = ft_strdup(grp->gr_name);
	return (elem);
}

t_elem	*ft_getstat(t_elem *elem, char *str)
{
	struct stat	st;
	long int	lk;

	if (lstat(str, &st) == -1)
	{
		perror("error lstat fonction !\n");
		exit(EXIT_FAILURE);
	}
	elem->mtime = st.st_mtimespec.tv_sec;
	elem->atime = st.st_atimespec.tv_sec;
	elem->st_dev = st.st_dev;
	elem->st_mode = st.st_mode;
	elem->st_nlink = st.st_nlink;
	elem->st_uid = st.st_uid;
	elem->st_gid = st.st_gid;
	elem->st_rdev = st.st_rdev;
	elem->mtime_c = ft_set_time(elem->mtime);
	elem->atime_c = ft_set_time(elem->atime);
	elem->st_size = st.st_size;
	elem->st_blocks = st.st_blocks;
	elem->lk_name = NULL;
	if (S_ISLNK(elem->st_mode))
	{
		if (!(elem->lk_name = (char *)malloc(sizeof(char) * (st.st_size + 1))))
		{
			perror("error ! Unable to malloc path link name.\n");
			exit(EXIT_FAILURE);
		}
		lk = readlink(str, elem->lk_name, st.st_size + 1);
		if (lk == -1)
		{
			perror("error readlink fonction !\n");
			exit(EXIT_FAILURE);
		}
		if (lk > st.st_size)
		{
			if (!ft_strncmp("stdin\0", elem->d_name, 6))
				elem->lk_name = ft_strdup("fd/0");
			else if (!ft_strncmp("stdout\0", elem->d_name, 7))
				elem->lk_name = ft_strdup("fd/1");
			else if (!ft_strncmp("stderr\0", elem->d_name, 7))
				elem->lk_name = ft_strdup("fd/2");
		}
		else
			elem->lk_name[st.st_size] = '\0';
	}
	return (elem);
}

t_elem	*ft_new_elem(struct dirent *d, char *str)
{
	t_elem	*elem;
	char	*s;

	if (d == NULL)
	{
		perror("error ! Unable to read file.\n");
		exit(EXIT_FAILURE);
	}
	if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
	{
		perror("error ! Unable to malloc structure elem.\n");
		exit(EXIT_FAILURE);
	}
	elem->d_namlen = d->d_namlen;
	elem->d_name = ft_strdup(d->d_name);
	s = ft_newstr_inmem(str, elem);
	elem = ft_getstat(elem, s);
	elem = ft_lstcpy_inelem(elem);
	ft_strdel(&s);
	return (elem);
}

t_elem	*ft_memrep(DIR *dir, char *str)
{
	struct dirent	*d;
	t_elem		*elem;
	t_elem		*save;

	d = readdir(dir);
	elem = ft_new_elem(d, str);
	save = elem;
	while ((d = readdir(dir)) != NULL)
	{
		elem->next = ft_new_elem(d, str);
		elem = elem->next;
	}
	elem->next = NULL;
	elem = save;
	return (elem);
}
