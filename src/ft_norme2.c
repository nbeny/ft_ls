/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norme2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:00:29 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/08 19:00:33 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	ft_lprint_norme(t_elem *elem, t_opt *opt)
{
	ft_putchar(elem->st_mode & S_IRUSR ? 'r' : '-');
	ft_putchar(elem->st_mode & S_IWUSR ? 'w' : '-');
	if (elem->st_mode & S_ISUID)
		ft_putchar(elem->st_mode & S_IXUSR ? 's' : 'S');
	else
		ft_putchar(elem->st_mode & S_IXUSR ? 'x' : '-');
	ft_putchar(elem->st_mode & S_IRGRP ? 'r' : '-');
	ft_putchar(elem->st_mode & S_IWGRP ? 'w' : '-');
	if (elem->st_mode & S_ISGID)
		ft_putchar(elem->st_mode & S_IXGRP ? 's' : 'S');
	else
		ft_putchar(elem->st_mode & S_IXGRP ? 'x' : '-');
	ft_putchar(elem->st_mode & S_IROTH ? 'r' : '-');
	ft_putchar(elem->st_mode & S_IWOTH ? 'w' : '-');
	if (elem->st_mode & S_ISVTX)
		ft_putchar(elem->st_mode & S_IXUSR ? 't' : 'T');
	else
		ft_putchar(elem->st_mode & S_IXOTH ? 'x' : '-');
	ft_print_time(elem, opt);
}

void	ft_print_time_norme(t_elem *elem, t_opt *opt)
{
	if (S_ISCHR(elem->st_mode) || S_ISBLK(elem->st_mode))
		ft_printf("  % *u, % *u", opt->j[1], major(elem->st_rdev), \
				opt->j[2], minor(elem->st_rdev));
	else
	{
		if (opt->j[0] == 1)
		{
			ft_putcstr(' ', (4 + opt->j[1]));
			ft_printf("% *u", opt->j[2], minor(elem->st_rdev));
		}
		else
			ft_printf(" % *lld", opt->i[3], elem->st_size);
	}
	if (opt->u != 1)
		ft_printf(" %s ", elem->mtime_c);
	else
		ft_printf(" %s ", elem->atime_c);
}

void	ft_checkall_size_norme(t_elem *elem, t_opt *opt)
{
	char *nlink;
	char *size;

	if (elem->d_name[0] != '.' || opt->a == 1 ||
		(opt->up_a == 1 && ft_strncmp(elem->d_name, ".\0", 2) &&
		ft_strncmp(elem->d_name, "..\0", 3)))
	{
		nlink = ft_ushort_itoa_base(elem->st_nlink, 10);
		size = ft_llitoa_base(elem->st_size, 10);
		if (ft_strlen(nlink) > opt->i[0])
			opt->i[0] = ft_strlen(nlink);
		if (ft_strlen(elem->pw_name) > opt->i[1])
			opt->i[1] = ft_strlen(elem->pw_name);
		if (ft_strlen(elem->gr_name) > opt->i[2])
			opt->i[2] = ft_strlen(elem->gr_name);
		if (ft_strlen(size) > opt->i[3])
			opt->i[3] = ft_strlen(size);
		free(size);
		size = NULL;
		free(nlink);
		nlink = NULL;
	}
}

void	ft_lets_go(t_elem *elem, t_opt *opt)
{
	t_elem *save;

	save = elem;
	while (save != NULL)
	{
		ft_no_optprint(save, opt);
		save = save->next;
	}
}
