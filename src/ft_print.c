/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 01:44:34 by nbeny             #+#    #+#             */
/*   Updated: 2017/04/12 01:44:37 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	ft_lprint(t_elem *elem, t_opt *opt)
{
  	if (S_ISBLK(elem->st_mode))
		ft_putchar('b');
	else if (S_ISCHR(elem->st_mode))
		ft_putchar('c');
	else if (S_ISDIR(elem->st_mode))
		ft_putchar('d');
	else if (S_ISFIFO(elem->st_mode))
		ft_putchar('p');
	else if (S_ISLNK(elem->st_mode))
		ft_putchar('l');
	else if (S_ISREG(elem->st_mode))
		ft_putchar('-');
	else if (S_ISSOCK(elem->st_mode))
		ft_putchar('s');
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

void	ft_print_time(t_elem *elem, t_opt *opt)
{
	ft_printf("  % *hu", opt->i[0], elem->st_nlink);
	if (opt->g == 0 && opt->n == 0)
		ft_printf(" %-*s ", opt->i[1], elem->pw_name);
	if (opt->o == 0 && opt->n == 0)
		ft_printf(" %-*s ", opt->i[2], elem->gr_name);
	if (opt->g == 0 && opt->n == 1)
		ft_printf(" %u ", elem->st_uid);
	if (opt->o == 0 && opt->n == 1)
		ft_printf("  %u ", elem->st_gid);
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

void	ft_checkall_size(t_elem *elem, t_opt *opt)
{
	t_elem	*save;
	char	*nlink;
	char	*size;

	save = elem;
	opt->i[0] = 0;
	opt->i[1] = 0;
	opt->i[2] = 0;
	opt->i[3] = 0;
	while (elem != NULL)
	{
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
		elem = elem->next;
	}
	elem = save;
}

void	ft_no_optprint(t_elem *elem, t_opt *opt)
{
	if (elem->d_name[0] != '.' || opt->a == 1 ||
		(opt->up_a == 1 && ft_strncmp(elem->d_name, ".\0", 2) &&
		ft_strncmp(elem->d_name, "..\0", 3)))
	{
		if (opt->l == 1)
			ft_lprint(elem, opt);
		ft_putstr(elem->d_name);
		if (S_ISLNK(elem->st_mode) && opt->l == 1)
			ft_printf(" -> %s", elem->lk_name);
		ft_putchar('\n');
	}
}

void	ft_print(t_elem *elem, t_opt *opt, char *str)
{
	t_elem		*save;
	blkcnt_t	total;

	total = 0;
	save = elem;
	ft_check_str(str, opt);
	if (opt->l == 1)
	{
		while (elem != NULL)
		{
			if (elem->d_name[0] != '.' || opt->a == 1 ||
				(opt->up_a == 1 &&
				ft_strncmp(elem->d_name, ".\0", 2) &&
				ft_strncmp(elem->d_name, "..\0", 3)))
				total = total + elem->st_blocks;
			elem = elem->next;
		}
		if (save->next->next != NULL)
			ft_printf("total %d\n", total);
		elem = save;
		ft_checkall_size(elem, opt);
		ft_checkdev_size(elem, opt);
	}
	while (elem != NULL)
	{
		ft_no_optprint(elem, opt);
		elem = elem->next;
	}
	elem = save;
}
