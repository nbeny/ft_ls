#include "../include/ft_ls.h"

t_elem	*ft_is_source(char *str)
{
	struct stat	st;
	t_elem		*elem;

	if (lstat(str, &st) == -1)
	{
		perror("error lstat fonction !\n");
		exit(EXIT_FAILURE);
	}
	if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
	{
		perror("error ! Unable to malloc structure elem.\n");
		exit(EXIT_FAILURE);
	}
	elem->d_name = ft_strdup(str);
	elem = ft_getstat(elem, str);
	elem = ft_lstcpy_inelem(elem);
	return (elem);
}

void	ft_print_source(t_elem *el, t_opt *opt)
{
	t_elem	*save;

	ft_checkall_size(el, opt);
	save = el;
	if (opt->r == 0)
		while (save != NULL)
		{
			if (opt->l == 1)
				ft_lprint(save, opt);
			ft_putstr(save->d_name);
			if (S_ISLNK(save->st_mode) && opt->l == 1)
				ft_printf(" -> %s", save->lk_name);
			ft_putchar('\n');
			save = save->next;
		}
	else
	{
		while (save->next != NULL)
			save = save->next;
		while (save->previous != NULL)
		{
			if (opt->l == 1)
				ft_lprint(save, opt);
			ft_putstr(save->d_name);
			if (S_ISLNK(save->st_mode) && opt->l == 1)
				ft_printf(" -> %s", save->lk_name);
			ft_putchar('\n');
			save = save->previous;
		}
	}
}

void	ft_check_source(char **av, t_opt *opt, int i)
{
	t_elem	*el;
	t_elem	*save;
	int		j;

	j = 0;
	el = NULL;
	while (av[++i] != NULL)
	{
		if (ft_is_src(av[i]) == 2)
			j = 1;
		if (ft_is_src(av[i]) == 1)
		{
			opt->isarg[0] = 1;
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
				j = 1;
			if (ft_is_src(av[i]) == 1)
			{
				save->next = ft_is_source(av[i]);
				save = save->next;
			}
		}
		save->next = NULL;
		save = el;
		ft_trirep(el, opt);
		el = el->next;
		ft_print_source(el, opt);
		if (j == 1)
			ft_putchar('\n');
		while (save != NULL)
		{
			el = save;
			save = save->next;
			free(el);
			el = NULL;
		}
	}
}

int	ft_is_dir(char *str)
{
	DIR			*d;

	if ((d = opendir(str)) != NULL)
	{
		closedir(d);
		return (1);
	}
	return (0);
}

int	ft_is_src(char *str)
{
	struct stat	st;

	if (str == NULL)
		return (0);
	if (lstat(str, &st) == -1)
	{
		ft_printf("ls: %s: No such file or directory\n", str);
		return (-1);
	}
	if (S_ISDIR(st.st_mode))
		return (2);
	return (1);
}
