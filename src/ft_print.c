#include "../include/ft_ls.h"

void	ft_lprint(t_elem *elem, t_opt *opt)
{
	if(S_ISBLK(elem->st_mode))
		ft_putchar('b');
	else if(S_ISCHR(elem->st_mode))
		ft_putchar('c');
	else if(S_ISDIR(elem->st_mode))
		ft_putchar('d');
	else if(S_ISFIFO(elem->st_mode))
		ft_putchar('p');
	else if(S_ISLNK(elem->st_mode))
		ft_putchar('l');
	else if(S_ISREG(elem->st_mode))
		ft_putchar('-');
	else if(S_ISSOCK(elem->st_mode))
		ft_putchar('s');

	ft_putchar(elem->st_mode & S_IRUSR ? 'r' : '-');
	ft_putchar(elem->st_mode & S_IWUSR ? 'w' : '-');
	ft_putchar(elem->st_mode & S_IXUSR ? 'x' : '-');
	ft_putchar(elem->st_mode & S_IRGRP ? 'r' : '-');
	ft_putchar(elem->st_mode & S_IWGRP ? 'w' : '-');
	ft_putchar(elem->st_mode & S_IXGRP ? 'x' : '-');
	ft_putchar(elem->st_mode & S_IROTH ? 'r' : '-');
	ft_putchar(elem->st_mode & S_IWOTH ? 'w' : '-');
	ft_putchar(elem->st_mode & S_IXOTH ? 'x' : '-');

	ft_printf("  % *hu", opt->i[0], elem->st_nlink);
	ft_printf(" %-*s", opt->i[1], elem->pw_name);
	ft_printf("  %-*s", opt->i[2], elem->gr_name);
	ft_printf("  % *lld", opt->i[3], elem->st_size);
	ft_print_time(elem, opt);
}

void	ft_print_time(t_elem *elem, t_opt *opt)
{
	char *str;

	if (opt->u != 1)
	{
		str = ft_strsub(elem->birthtime_c, 4, 12);
		ft_printf(" %s ", str);
	}
	else
	{
		str = ft_strsub(elem->mtime_c, 4, 12);
		ft_printf(" %s ", str);
	}
}

void	ft_checkall_size(t_elem *elem, t_opt *opt)
{
	t_elem	*save;
	char	*nlink;
	char	*size;

	save = elem;
	opt->i[0] = 0;
	opt->i[1] = 0;
	opt->i[2] = 0;
	opt->i[3] = 0;
	while (elem != NULL)
	{
		nlink = ft_itoa(elem->st_nlink);
		size = ft_llitoa_base(elem->st_size, 10);
		if (ft_strlen(nlink) > opt->i[0])
			opt->i[0] = ft_strlen(nlink);
		if (ft_strlen(elem->pw_name) > opt->i[1])
			opt->i[1] = ft_strlen(elem->pw_name);
		if (ft_strlen(elem->gr_name) > opt->i[2])
			opt->i[2] = ft_strlen(elem->gr_name);
		if (ft_strlen(size) > opt->i[3])
			opt->i[3] = ft_strlen(size);
		free(nlink);
		free(size);
		elem = elem->next;
	}
	elem = save;
}

void	ft_no_optprint(t_elem *elem, t_opt *opt)
{
	if (elem->d_name[0] != '.' || opt->a == 1 ||
		(opt->up_a == 1 && elem->d_name[0] != '.' &&
		elem->d_name[1] != '\0') || (elem->d_name[0] != '.' &&
		elem->d_name[1] != '.' && elem->d_name[2] != '\0' &&
		opt->up_a == 1))
	{
		if (elem->d_namlen <= 255)
		{
			if (opt->l == 1)
				ft_lprint(elem, opt);
			ft_putendl(elem->d_name);
		}
		else
		{
			if (opt->l == 1)
				ft_lprint(elem, opt);
			ft_putendl(elem->d_name);
		}
	}
}

void	ft_print(t_elem *elem, t_opt *opt, char *str)
{
	t_elem		*save;
	blkcnt_t	total;	

	total = 0;
	save = elem;
	if (opt->up_r == 1 && opt->r_rep == 1 &&
		(ft_strcmp(str, ".") || ft_strcmp(str, "/")))
		ft_printf("\n%s:\n", str);
	else if (opt->up_r == 1 && opt->r_rep == 1)
		ft_printf("\n./%s:\n", str);
	else
		opt->r_rep = 1;
	if (opt->l == 1)
	{
		while (elem != NULL)
		{
			total = total + elem->st_blocks;
			elem = elem->next;
		}
		ft_printf("total %d\n", total);
		elem = save;
		ft_checkall_size(elem, opt);
	}
	while (elem != NULL)
	{
		ft_no_optprint(elem, opt);
		elem = elem->next;
	}
	elem = save;
}
