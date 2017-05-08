/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 01:44:10 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/08 19:50:48 by nbeny            ###   ########.fr       */
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
	DIR				*dir;

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
	while (opt->up_r == 1 && save != NULL)
	{
		if ((opt->a == 1 || opt->up_a == 1 ||
			save->d_name[0] != '.') && ft_isrep(save) == 1 &&
			ft_strncmp(save->d_name, ".\0", 2) &&
			ft_strncmp(save->d_name, "..\0", 3))
			ft_ls(ft_newstr(str, save), opt);
		save = save->next;
	}
	ft_end(el, dir, str);
	return (0);
}

int		main(int ac, char **av)
{
	int				i[2];
	t_opt			*opt;
	t_elem			*elem;

	i[0] = 0;
	i[1] = 1;
	elem = NULL;
	opt = ft_main_norme(ac);
	while (av[++i[0]] != NULL && av[i[0]][0] == '-' && av[i[0]][1] != '-')
	{
		ft_check_opt(av[i[0]], opt);
		i[1] += 1;
	}
	--i[0];
	ft_check_source(av, opt, i[0]);
	elem = ft_check_dir(av, opt, i[0]);
	ft_main_norme2(elem, opt);
	if ((av[i[0] + 1] == NULL && ac != 1) || (av[i[0] + 2] == NULL &&
		av[i[0] + 1][0] == '-' && av[i[0] + 1][1] == '-'))
		ft_ls(ft_strdup("."), opt);
	free(opt);
	opt = NULL;
	return (0);
}
