/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:59:12 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/08 18:59:21 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_elem	*ft_check_dir_norme(char **av, int i, t_opt *opt)
{
	t_elem	*el;

	el = NULL;
	while (av[++i] != NULL)
	{
		if (av[i][0] == '-' && av[i][1] == '-' &&
			av[i + 1] != NULL)
			i++;
		if (av[i][0] == '-' && av[i][1] == '-' &&
			av[i + 1] == NULL)
			return (NULL);
		if (ft_is_src(av[i]) == 2)
		{
			el = ft_first_source();
			break ;
		}
	}
	opt->norme = i;
	return (el);
}

t_elem	*ft_check_dir(char **av, t_opt *opt, int i)
{
	t_elem	*el;
	t_elem	*save;

	save = NULL;
	el = ft_check_dir_norme(av, i, opt);
	i = opt->norme;
	--i;
	if (el != NULL)
	{
		save = el;
		while (av[i++] != NULL)
		{
			if (ft_is_src(av[i]) == 2)
			{
				save->next = ft_is_source(av[i]);
				save = save->next;
			}
		}
		save->next = NULL;
		save = el;
		el = ft_free_firstone(save);
		ft_trirep(el, opt);
	}
	return (el);
}

void	ft_check_dev_size_norme(t_elem *elem, t_opt *opt)
{
	char	*maj;
	char	*min;

	if (elem->d_name[0] != '.' || opt->a == 1 ||
		(opt->up_a == 1 &&
		ft_strncmp(elem->d_name, ".\0", 2) &&
		ft_strncmp(elem->d_name, "..\0", 3)))
	{
		maj = ft_uitoa_base(major(elem->st_rdev), 10);
		min = ft_uitoa_base(minor(elem->st_rdev), 10);
		if (S_ISCHR(elem->st_mode) || S_ISBLK(elem->st_mode))
		{
			opt->j[0] = 1;
			if (ft_strlen(maj) > opt->j[1])
				opt->j[1] = ft_strlen(maj);
			if (ft_strlen(min) > opt->j[2])
				opt->j[2] = ft_strlen(min);
		}
		free(maj);
		maj = NULL;
		free(min);
		min = NULL;
	}
}

void	ft_checkdev_size(t_elem *elem, t_opt *opt)
{
	t_elem	*save;

	save = elem;
	opt->j[0] = 0;
	opt->j[1] = 0;
	opt->j[2] = 0;
	while (elem != NULL)
	{
		ft_check_dev_size_norme(elem, opt);
		elem = elem->next;
	}
	elem = save;
}
