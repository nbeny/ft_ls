#include "../include/ft_ls.h"

void	ft_reverse_order(t_elem *elem)
{
	int		i[2];
	t_elem	*rev;
	t_elem	*save;

	i[0] = 0;
	save = elem;
	rev = elem;
	while (rev != NULL)
	{
		rev = rev->next;
		i[0]++;
	}
	while (--i[0] != 0)
	{
		i[1] = 0;
		while (i[1] == i[0])
		{
			elem = elem->next;
			i[1]++;
		}
		rev->next = elem;
		elem = save;
	}
	rev->next = NULL;
	elem = rev;
}

void	ft_trirep_t(t_elem *elem)
{
	t_elem *save;
	t_elem *tmp;

	save = elem;
	while (elem->next != NULL)
	{
		if (elem->mtime > elem->next->mtime)
		{
			tmp = elem;
			elem = elem->next;
			elem->next = tmp;
			elem = save;
		}
		else
			elem = elem->next;
	}
	elem = save;
}

void	ft_trirep_u(t_elem *elem)
{
	t_elem *save;
	t_elem  *tmp;

	save = elem;
	while (elem->next != NULL)
	{
		if (elem->atime > elem->next->atime)
		{
			tmp = elem;
			elem = elem->next;
			elem->next = tmp;
			elem = save;
		}
		else
			elem = elem->next;
	}
	elem = save;
}

void	ft_trirep_ascii(t_elem *elem)
{
	t_elem	*save;
	t_elem	*tmp;

	save = elem;
	while (elem->next != NULL)
	{
		if ((ft_strcmp(elem->d_name, elem->next->d_name)) == 0)
		{
			tmp = elem;
			elem = elem->next;
			elem->next = tmp;
			elem = save;
		}
		else
			elem = elem->next;
	}
	elem = save;
}

void	ft_trirep(t_elem *elem, t_opt *opt)
{
	if (opt->f == 1)
		opt->a = 1;
	else if (opt->t == 1 && opt->u != 1)
		ft_trirep_t(elem);
	else if (opt->u == 1 && opt->t == 1)
		ft_trirep_u(elem);
	else
		ft_trirep_ascii(elem);
	if (opt->r == 1)
		ft_reverse_order(elem);
}
