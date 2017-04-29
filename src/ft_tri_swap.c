/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 01:45:05 by nbeny             #+#    #+#             */
/*   Updated: 2017/04/12 01:45:06 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/ft_ls.h>

void	ft_swap_char(t_elem *save, t_elem *elsa)
{
	char *swap;

	swap = ft_strdup(save->d_name);
	ft_strdel(&save->d_name);
	save->d_name = ft_strdup(elsa->d_name);
	ft_strdel(&elsa->d_name);
	elsa->d_name = ft_strdup(swap);
	ft_strdel(&swap);
	swap = ft_strdup(save->lk_name);
	ft_strdel(&save->lk_name);
	save->lk_name = ft_strdup(elsa->lk_name);
	ft_strdel(&elsa->lk_name);
	elsa->lk_name = ft_strdup(swap);
	ft_strdel(&swap);
	swap = ft_strdup(save->pw_name);
	ft_strdel(&save->pw_name);
	save->pw_name = ft_strdup(elsa->pw_name);
	ft_strdel(&elsa->pw_name);
	elsa->pw_name = ft_strdup(swap);
	ft_strdel(&swap);
	swap = ft_strdup(save->gr_name);
	ft_strdel(&save->gr_name);
	save->gr_name = ft_strdup(elsa->gr_name);
	ft_strdel(&elsa->gr_name);
	elsa->gr_name = ft_strdup(swap);
	ft_strdel(&swap);
}

void	ft_swap_time(t_elem *save, t_elem *elsa)
{
	char		*swap;
	time_t		ss;
	__uint8_t	d_namlen;

	swap = ft_strdup(save->atime_c);
	ft_strdel(&save->atime_c);
	save->atime_c = ft_strdup(elsa->atime_c);
	ft_strdel(&elsa->atime_c);
	elsa->atime_c = ft_strdup(swap);
	ft_strdel(&swap);
	swap = ft_strdup(save->mtime_c);
	ft_strdel(&save->mtime_c);
	save->mtime_c = ft_strdup(elsa->mtime_c);
	ft_strdel(&elsa->mtime_c);
	elsa->mtime_c = ft_strdup(swap);
	ft_strdel(&swap);
	ss = save->atime;
	save->atime = elsa->atime;
	elsa->atime = ss;
	ss = save->mtime;
	save->mtime = elsa->mtime;
	elsa->mtime = ss;
	d_namlen = save->d_namlen;
	save->d_namlen = elsa->d_namlen;
	elsa->d_namlen = d_namlen;
}

void	ft_swap_st(t_elem *save, t_elem *elsa)
{
	dev_t	st_dev;
	mode_t	st_mode;
	nlink_t	st_nlink;
	dev_t	st_rdev;
	uid_t	st_uid;
	gid_t	st_gid;

	st_dev = save->st_dev;
	save->st_dev = elsa->st_dev;
	elsa->st_dev = st_dev;
	st_mode = save->st_mode;
	save->st_mode = elsa->st_mode;
	elsa->st_mode = st_mode;
	st_nlink = save->st_nlink;
	save->st_nlink = elsa->st_nlink;
	elsa->st_nlink = st_nlink;
	st_rdev = save->st_rdev;
	save->st_rdev = elsa->st_rdev;
	elsa->st_rdev = st_rdev;
	st_uid = save->st_uid;
	save->st_uid = elsa->st_uid;
	elsa->st_uid = st_uid;
	st_gid = save->st_gid;
	save->st_gid = elsa->st_gid;
	elsa->st_gid = st_gid;
}

void	ft_swap_all(t_elem *save, t_elem *elsa)
{
	off_t		st_size;
	blkcnt_t	st_blocks;

	ft_swap_char(save, elsa);
	ft_swap_time(save, elsa);
	ft_swap_st(save, elsa);
	st_size = save->st_size;
	save->st_size = elsa->st_size;
	elsa->st_size = st_size;
	st_blocks = save->st_blocks;
	save->st_blocks = elsa->st_blocks;
	elsa->st_blocks = st_blocks;
}
