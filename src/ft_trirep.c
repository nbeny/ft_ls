#include "../include/ft_ls.h"

void	ft_reverse_order(t_elem *elem)
{
	int		i[2];
	t_elem	*rev;
	t_elem	*save;
	t_elem	*tmp;

	i[0] = 0;
	rev = elem;
	tmp = elem;
	while (rev->next != NULL)
	{
		rev = rev->next;
		i[0]++;
	}
	save = rev;
	while (i[0] != 0)
	{
		i[1] = 0;
		elem = tmp;
		while (i[1] != i[0])
		{
			elem = elem->next;
			i[1]++;
		}
		rev->next = elem;
		rev = rev->next;
		i[0]--;
	}
	rev->next = NULL;
	elem = save;
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
			tmp = elem->next;
			elem->next = elem;
			elem = tmp;
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
			tmp = elem->next;
			elem->next = elem;
			elem = tmp;
			elem = save;
		}
		else
			elem = elem->next;
	}
	elem = save;
}

void	ft_trirep_ascii(t_elem *elem)
{
	t_elem	*nxt;
	t_elem	*root;
	t_elem	*tmp;
	t_elem	*ptmp;

	tmp = NULL;
	ptmp = NULL;
	root = elem;
	nxt = elem->next;
	while (nxt != NULL)
	{
		while (root != NULL)
		{
			if (ft_strcmp(root->d_name, nxt->d_name) > 0)
			{
				ft_printf("try\n");
				tmp = nxt;
				ptmp = nxt->next;
				nxt = root;
				nxt = root->next;
				root = tmp;
				root->next = ptmp;
			}
			root = root->next;
		}
		root = elem;
		nxt = nxt->next;
	}
}

void	ft_trirep(t_elem *elem, t_opt *opt)
{
	if (opt->f == 1)
		opt->a = 1;
	else if (opt->t == 1 && opt->u == 0)
		ft_trirep_t(elem);
	else if (opt->t == 1 && opt->u == 1)
		ft_trirep_u(elem);
	else
		ft_trirep_ascii(elem);
	if (opt->r == 1)
		ft_reverse_order(elem);
}
