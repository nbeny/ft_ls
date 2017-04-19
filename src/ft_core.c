/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 01:44:10 by nbeny             #+#    #+#             */
/*   Updated: 2017/04/12 01:44:12 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_opt	*ft_init_opt(t_opt *opt)
{
	opt->a = 0;
	opt->up_a = 0;
	opt->up_r = 0;
	opt->l = 0;
	opt->r = 0;
	opt->f = 0;
	opt->t = 0;
	opt->u = 0;
	opt->up_g = 0;
	opt->r_rep = 0;
	opt->n = 0;
	opt->g = 0;
	opt->o = 0;
	opt->isarg[0] = 0;
	opt->isarg[1] = 0;
	return (opt);
}

int		ft_ls(char *str, t_opt *opt)
{
	t_elem			*el;
	t_elem			*save;
	DIR			*dir;

	dir = opendir(str);
	if (dir == NULL)
	{
		perror("ls: No such file or directory\n");
		return (-1);
	}
	el = ft_memrep(dir, str);
	ft_trirep(el, opt);
	ft_print(el, opt, str);
	save = el;
	if (opt->up_r == 1 && opt->r == 0)
		while (el != NULL)
		{
			if (ft_isrep(el) == 1 && ft_strncmp(".\0", el->d_name, 2) &&
				ft_strncmp("..\0", el->d_name, 3))
				ft_ls(ft_newstr(str, el), opt);
			el = el->next;
		}
	else if (opt->up_r == 1 && opt->r == 1)
	{
		while (el->next != NULL)
			el = el->next;
		while (el != NULL)
		{
			if (ft_isrep(el) == 1 && ft_strncmp(".\0", el->d_name, 2) &&
				ft_strncmp("..\0", el->d_name, 3))
				ft_ls(ft_newstr(str, el), opt);
			el = el->previous;
		}
	}
	el = save;
	return (0);
}

int		main(int ac, char **av)
{
	int			i[2];
	t_opt			*opt;
	t_elem			*elem;
	t_elem			*elem_sa;

	i[0] = 0;
	i[1] = 1;
	elem = NULL;
	if (!(opt = (t_opt *)malloc(sizeof(t_opt))))
	{
		perror("error ! unable to  malloc option.\n");
		exit (EXIT_FAILURE);
	}
	opt = ft_init_opt(opt);
	if (ac == 1)
		ft_ls(ft_strdup("."), opt);
	while (av[++i[0]] != NULL && av[i[0]][0] == '-')
	{
		ft_check_opt(av[i[0]], opt);
		i[1] += 1;
	}
	--i[0];
	ft_check_source(av, opt, i[0]);
	elem = ft_check_dir(av, opt, i[0]);
	elem_sa = elem;
	if (opt->r == 0 && elem != NULL)
	{
		elem = elem->next;
		if (elem->next != NULL && elem->next->next != NULL)
			opt->isarg[0] = 1;
		while (elem != NULL)
		{
			ft_ls(elem->d_name, opt);
			elem = elem->next;
		}
	}
	else if (opt->r == 1 && elem != NULL)
	{
		if (elem->next != NULL && elem->next->next != NULL)
			opt->isarg[0] = 1;
		while (elem->next != NULL)
			elem = elem->next;
		while (elem->previous != NULL)
		{
			ft_ls(elem->d_name, opt);
			elem = elem->previous;
		}
	}
	elem = elem_sa;
	if (av[i[0] + 1] == NULL && ac != 1)
		ft_ls(ft_strdup("."), opt);
	free(opt);
	opt = NULL;
	return (0);
}
