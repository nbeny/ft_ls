#include "../include/ft_ls.h"

void	ft_noprint(t_elem **elem, t_opt *opt)
{
	ft_putstr(elem->name);
}

void	ft_print(t_elem **elem, t_opt *opt)
{
	t_elem	*save;

	save = *elem;
	while (*elem->next != NULL)
	{
		if (opt->l == 0 && opt->up_g == 0)
			ft_no_optprint(elem, opt);
		if (opt->l == 1 && opt->up_g == 0)
			ft_lprint(elem, opt);
		if (opt->l == 0 && opt->up_g == 1)
			ft_gprint(elem, opt);
		if (opt->l == 1 && opt->up_g == 1)
			ft_lgprint(elem, opt);
		*elem = *elem->next;
	}
	*elem = save;
}
