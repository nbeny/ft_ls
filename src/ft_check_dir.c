#include "../include/ft_ls.h"

t_elem	*ft_check_dir(char **av, t_opt *opt, int i)
{
	t_elem	*el;
	t_elem	*save;

	el = NULL;
	while (av[++i] != NULL)
	{
		if (ft_is_src(av[i]) == 2)
		{
			el = ft_first_source();
			break;
		}
	}
	--i;
	if (el != NULL)
	{
		save = el;
		while (av[i++] != NULL)
		{
			if (ft_is_src(av[i]) == 2)
			{
				save->next = ft_is_source(av[i]);
				save = save->next;
			}
		}
		save->next = NULL;
		save = el;
		ft_trirep(el, opt);
	}
	return (el);
}
