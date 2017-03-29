#include "../include/ft_ls.h"

t_opt	*ft_init_opt(t_opt *opt)
{
	opt->r = 0;
	opt->up_g = 0;
	opt->a = 0;
	opt->up_a = 0;
	opt->up_u = 0;
	opt->up_f = 0;
	opt->l = 0;
	opt->up_r = 0;
	return (opt);
}

int		ft_ls(char *str, t_opt *opt)
{
	struct dirent	*d;
	t_elem			*el;
	t_elem			*save;
	DIR			*dir;

	dir = opendir(str);
	if (dir == NULL)
	{
		perror("ls: No sush file or directory\n");
		return (-1);
	}
	el = ft_memrep(d, dir);
	ft_trirep(&el, opt);
	ft_print(&el, opt);
	save = el;
	while (el != NULL)
	{
		if (opt->up_r && ft_isrep(&el))
			ft_ls(ft_newstr(str), opt);
		el = el->next;
	}
	el = save;
	ft_freestyle(el);
	closedir(dir);
	return (0);
}

int		main(int ac, char **av)
{
	int			i[2];
	t_opt			*opt;

	i[0] = 0;
	i[1] = 1;
	if (!(opt = (t_opt *)malloc(sizeof(t_opt))))
	{
		perror("error ! unable to  malloc option.\n");
		exit (EXIT_FAILURE);
	}
	opt = ft_init_opt(opt);
	if (ac == 1)
		ft_ls(".", opt);
	while (av[++i[0]] != NULL)
	{
		if (av[i[0]][0] == '-')
		{
			ft_check_opt(av[i[0]], opt);
			i[1] += 1;
		}
		else
			ft_ls(av[i[0]], opt);
	}
	printf("[%i][%i]\n", i[0], i[1]);
	if (i[1] == i[0] && ac != 1)
		ft_ls(".", opt);
	return (0);
}
