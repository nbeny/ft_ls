#include "../include/ft_ls.h"

void	ft_reverse_list(t_elem *elem)
{
	t_elem	*save;
	t_elem	tmp;
	int		len;
	int		i;

	save = elem;
	len = 0;
	while (save != NULL)
	{
		len++;
		save = save->next;
	}
	save = elem;
	i = 0;
	while (i < len)
	{
		tmp = elem[i];
		elem[i] = elem[len - 1];
		elem[len - 1] = tmp;
		i++;
		len--;
	}
}

void	ft_revtri_ascii(t_elem *elem)
{
	t_elem	*save;
	int		i;

	i = 1;
	while (i)
	{
		i = 0;
		save = elem;
		while (save->next != NULL)
		{
			if (ft_strcmp(save->d_name, save->next->d_name) < 0)
			{
				i = 1;
				ft_tri_swap(save, elem);
			}
			else
				save = save->next;
		}
	}
}

void	ft_revtri_t(t_elem *elem)
{
	t_elem	*save;
	int		i;

	i = 1;
	while (i)
	{
		i = 0;
		save = elem;
		while (save->next != NULL)
		{
			if (save->mtime > save->next->mtime)
			{
				i = 1;
				ft_tri_swap(save, elem);
			}
			else
				save = save->next;
		}
	}
}

void	ft_revtri_u(t_elem *elem)
{
	t_elem	*save;
	int		i;

	i = 1;
	while (i)
	{
		i = 0;
		save = elem;
		while (save->next != NULL)
		{
			if (save->atime > save->next->atime)
			{
				i = 1;
				ft_tri_swap(save, elem);
			}
			else
				save = save->next;
		}
	}
}
