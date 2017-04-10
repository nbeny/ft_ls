#include <../include/ft_ls.h>

void	ft_tri_swap(t_elem *save, t_elem *elem)
{
	t_elem *before;
	t_elem *after;

	if (save == elem)
	{
		after = save->next;
		save->next = save->next->next;
		after->next = save;
		elem = after;
	}
	else
	{
		before = elem;
		after = save->next;
		while (before->next != save)
			before = before->next;
		before->next = after;
		save->next = after->next;
		after->next = save;
	}
}
