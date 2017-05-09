/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:58:59 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/08 18:59:02 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_elem	*ft_is_source(char *str)
{
	struct stat	st;
	t_elem		*elem;

	if (lstat(str, &st) == -1)
	{
		perror("error lstat fonction !\n");
		exit(EXIT_FAILURE);
	}
	if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
	{
		perror("error ! Unable to malloc structure elem.\n");
		exit(EXIT_FAILURE);
	}
	elem->d_name = ft_strdup(str);
	elem = ft_getstat(elem, str);
	elem = ft_lstcpy_inelem(elem);
	return (elem);
}

void	ft_print_source(t_elem *el, t_opt *opt)
{
	t_elem	*save;

	ft_checkall_size(el, opt);
	save = el;
	while (save != NULL)
	{
		if (opt->l == 1)
			ft_lprint(save, opt);
		ft_putstr(save->d_name);
		if (S_ISLNK(save->st_mode) && opt->l == 1)
			ft_printf(" -> %s", save->lk_name);
		ft_putchar('\n');
		save = save->next;
	}
}

void	ft_check_source(char **av, t_opt *opt, int i)
{
	t_elem	*el;
	t_elem	*save;

	opt->is = 0;
	el = ft_check_source_norme(av, opt, i);
	i = opt->norme;
	--i;
	if (el != NULL)
	{
		save = ft_check_source_norme2(av, opt, i, el);
		i = opt->norme;
		el = ft_free_firstone(save);
		ft_trirep(el, opt);
		ft_print_source(el, opt);
		if (opt->is == 1)
			ft_putchar('\n');
		ft_freestyle(el);
	}
}

int		ft_is_dir(char *str)
{
	DIR			*d;

	if ((d = opendir(str)) != NULL)
	{
		closedir(d);
		return (1);
	}
	return (0);
}

int		ft_is_src(char *str)
{
	struct stat	st;

	if (str == NULL)
		return (0);
	if (lstat(str, &st) == -1)
	{
		ft_printf("ls: %s: No such file or directory\n", str);
		return (-1);
	}
	if (S_ISDIR(st.st_mode))
		return (2);
	return (1);
}
