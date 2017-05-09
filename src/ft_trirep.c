/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trirep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 01:45:17 by nbeny             #+#    #+#             */
/*   Updated: 2017/04/12 01:45:39 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	ft_trirep_tt(t_elem *elem)
{
	t_elem	*save;
	t_elem	*elsa;

	save = elem;
	while (save->next != NULL)
	{
		elsa = save->next;
		while (elsa != NULL)
		{
			if (save->mtime < elsa->mtime)
				ft_swap_all(save, elsa);
			elsa = elsa->next;
		}
		save = save->next;
	}
}

void	ft_trirep_u(t_elem *elem)
{
	t_elem	*save;
	t_elem	*elsa;

	save = elem;
	while (save->next != NULL)
	{
		elsa = save->next;
		while (elsa != NULL)
		{
			if (save->atime < elsa->atime)
				ft_swap_all(save, elsa);
			elsa = elsa->next;
		}
		save = save->next;
	}
}

void	ft_trirep_ascii(t_elem *elem)
{
	t_elem	*save;
	t_elem	*elsa;

	save = elem;
	while (save->next != NULL)
	{
		elsa = save->next;
		while (elsa != NULL)
		{
			if (ft_strcmp(save->d_name, elsa->d_name) > 0)
				ft_swap_all(save, elsa);
			elsa = elsa->next;
		}
		save = save->next;
	}
}

void	ft_trirep(t_elem *elem, t_opt *opt)
{
	if (opt->f == 1)
		opt->a = 1;
	else if (opt->t == 1 && opt->u == 0)
		ft_trirep_tt(elem);
	else if (opt->t == 1 && opt->u == 1)
		ft_trirep_u(elem);
	else
		ft_trirep_ascii(elem);
	if (opt->r == 1)
		ft_revlist(elem);
}
