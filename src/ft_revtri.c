#include "../include/ft_ls.h"

void	ft_revlist(t_elem *elem)
{
	t_elem	*x;
	t_elem	*y;
	size_t	i[3];

	i[0] = 0;
	i[1] = 0;
	x = elem;
	y = elem;
	while (x != NULL)
	{
		x = x->next;
		i[0] += 1;
	}
	while (i[1]++ < i[0]--)
	{
		i[2] = 0;
		x = elem;
		while (i[2]++ < i[0])
			x = x->next;
		ft_swap_all(x, y);
		y = y->next;
	}
}
