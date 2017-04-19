#include "../include/ft_ls.h"

void	ft_reverse_list(t_elem *elem)
{
	t_elem	*save;
	t_elem	*tmp;
	t_elem	*new_elem;
	int		len;
	int		i;

	save = elem;
	len = 0;
	if (save->next != NULL)
	{
		while (save->next->next != NULL)
		{
			len++;
			save = save->next;
		}
		tmp = save->next;
		tmp->previous = save; 
		new_elem = tmp;
	}
	while (--len >= 0)
	{
		i = 0;
		save = elem;
		while (i < len)
		{
			save = save->next;
			i++;
		}
		tmp = save->next;
		tmp->previous = save;
	}
	elem->previous = NULL;
	elem = new_elem;
}

void    ft_previous_print(t_elem *elem, t_opt *opt)
{
	while (elem->next != NULL)
		elem = elem->next;
	while (elem != NULL)
	{
		ft_no_optprint(elem, opt);
		elem = elem->previous;
	}
}
