/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norme.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:00:07 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/08 19:00:10 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_elem	*ft_check_source_norme(char **av, t_opt *opt, int i)
{
	t_elem	*el;

	opt->is = 0;
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
			opt->is = 1;
		if (ft_is_src(av[i]) == 1)
		{
			opt->isarg[0] = 1;
			el = ft_first_source();
			break ;
		}
	}
	opt->norme = i;
	return (el);
}

t_elem	*ft_check_source_norme2(char **av, t_opt *opt, int i, t_elem *el)
{
	t_elem *save;

	save = el;
	while (av[i++] != NULL)
	{
		if (ft_is_src(av[i]) == 2)
			opt->is = 1;
		if (ft_is_src(av[i]) == 1)
		{
			save->next = ft_is_source(av[i]);
			save = save->next;
		}
	}
	opt->norme = i;
	save->next = NULL;
	return (el);
}

void	ft_end(t_elem *el, DIR *dir, char *str)
{
	ft_freestyle(el);
	closedir(dir);
	ft_strdel(&str);
}

t_opt	*ft_main_norme(int ac)
{
	t_opt *opt;

	opt = NULL;
	if (!(opt = (t_opt *)malloc(sizeof(t_opt))))
	{
		perror("error ! unable to  malloc option.\n");
		exit(EXIT_FAILURE);
	}
	opt = ft_init_opt(opt);
	if (ac == 1)
		ft_ls(ft_strdup("."), opt);
	return (opt);
}

void	ft_main_norme2(t_elem *elem, t_opt *opt)
{
	t_elem *save;

	save = elem;
	if (elem != NULL)
	{
		if (elem->next != NULL)
			opt->isarg[0] = 1;
		while (elem != NULL)
		{
			ft_ls(elem->d_name, opt);
			elem = elem->next;
		}
	}
	ft_free_arg(save);
}
