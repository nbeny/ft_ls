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
	ft_lprint_norme(elem, opt);
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
	ft_print_time_norme(elem, opt);
}

void	ft_checkall_size(t_elem *elem, t_opt *opt)
{
	t_elem	*save;

	save = elem;
	opt->i[0] = 0;
	opt->i[1] = 0;
	opt->i[2] = 0;
	opt->i[3] = 0;
	while (elem != NULL)
	{
		ft_checkall_size_norme(elem, opt);
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
	ft_lets_go(elem, opt);
}
