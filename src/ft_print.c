#include "../include/ft_ls.h"

void	ft_print(t_elem **elem, t_opt *opt)
{
	while (*elem->next != NULL)
	{
		if (opt->l == 1 && opt->up_g == 0 && opt->up_f == 0)
			ft_lonly(elem);
		if (opt->l == 0 && opt->up_g == 1 && opt->up_f == 0)
			ft_gonly(elem);
		if (opt->l == 1 && opt->up_g == 1 && opt->up_f == 0)
			ft_lgo(elem);
		if (opt->l == 0 && opt->up_g == 0 && opt->up_f == 1)
			ft_f(elem);
		if (opt->l == 1 && opt->up_g == 0 && opt->up_f == 1)
			ft_lf(elem);
		if (opt->l == 0 && opt->up_g == 1 && opt->up_f == 1)
			ft_gf(elem);
		if (opt->l == 1 && opt->up_g == 1 && opt->up_f == 1)
			ft_lgf(elem);
		*elem = *elem->next;
	}
}
