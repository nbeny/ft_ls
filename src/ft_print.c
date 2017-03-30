#include "../include/ft_ls.h"

void	ft_lprint(t_elem **elem, t_opt *opt)
{
	if(S_ISBLK(*elem.st_mode))
		ft_putchar('b');
	else if(S_ISCHR(*elem.st_mode))
		ft_putchar('c');
	else if(S_ISDIR(*elem.st_mode))
		ft_putchar('d');
	else if(S_ISFIFO(*elem.st_mode))
		ft_putchar('p');
	else if(S_ISLNK(*elem.st_mode))
		ft_putchar('l');
	else if(S_ISREG(*elem.st_mode))
		ft_putchar('-');
	else if(S_ISSOCK(*elem.st_mode))
		ft_putchar('s');

	ft_putchar(*elem.st_mode & S_IRUSR ? 'r' : '-');
	ft_putchar(*elem.st_mode & S_IWUSR ? 'w' : '-');
	ft_putchar(*elem.st_mode & S_IXUSR ? 'x' : '-');
	ft_putchar(*elem.st_mode & S_IRGRP ? 'r' : '-');
	ft_putchar(*elem.st_mode & S_IWGRP ? 'w' : '-');
	ft_putchar(*elem.st_mode & S_IXGRP ? 'x' : '-');
	ft_putchar(*elem.st_mode & S_IROTH ? 'r' : '-');
	ft_putchar(*elem.st_mode & S_IWOTH ? 'w' : '-');
	ft_putchar(*elem.st_mode & S_IXOTH ? 'x' : '-');

	
	ft_printf("  %*hu", i[0], *elem.st_nlink);
	ft_printf(" %*s", i[1], *elem->pw_name);
	ft_printf("  %*s", i[2], *elem->gr_name);
	ft_printf("  %*lld", i[3], *elem->st_size);
	ft_printf(" %-24.24s ", ctime(elem->st_mtimespec));

	if ((opendir(*elem->d_name)) != NULL)
		{
			couleur("34");
			ft_printf("%s\n", *elem->d_name);
			couleur("0");
		}
	else if (S_ISREG(*elem.st_mode) && *elem.st_mode & 0111)
		{
			couleur("32");
			ft_printf("%s\n", *elem->d_name);
			couleur("0");
		}
	/* ((status.st_mode & S_IFMT) != S_IFREG) : .exe */
	else
		ft_printf("%s\n", *elem->d_name);
}

void	ft_checkall_size(t_elem **elem)
{
	t_elem	*save;
	char	*nlink;
	char	*size;

	save = *elem;
	while (*elem != NULL)
	{
		nlink = ft_itoa(*elem->st_nlink);
		size = ft_itoa(*elem->st_size);
		if (ft_strlen(nlink) > *elem->i[0])
			*elem->i[0] = ft_strlen(nlink);
		if (ft_strlen(*elem->pw_name) > *elem->i[1])
			*elem->i[1] = ft_strlen(*elem->pw_name);
		if (ft_strlen(*elem->pw_name) > *elem->i[2])
			*elem->i[2] = ft_strlen(*elem->gr_name);
		if (ft_strlen(size) > *elem->i[3])
			*elem->i[3] = ft_strlen(size);
		free(nlink);
		free(size);
		*elem = *elem->next;
	}
	*elem = save;
}

void	ft_no_optprint(t_elem **elem, t_opt *opt)
{
	if (*elem->d_name[0] != '.' || opt->a == 1 ||
		(opt->up_a == 1 && (*elem->d_name[0] != '.' &&
		*elem->d_name[1] != '\0') || (*elem->d_name[0] != '.' &&
		*elem->d_name[1] != '.' && *elem->d_name[2] != '\0')))
	{
		if (*elem->d_namlen <= 255)
			ft_putnstr(*elem->d_name, *elem->d_namlen);
		else
			ft_putnstr(*elem->d_name, 255);
	}
	ft_putchar('\n');
}

void	ft_print(t_elem **elem, t_opt *opt, char *str)
{
	t_elem	*save;

	save = *elem;
	if (opt->up_r == 1 && opt->r_rep == 1)
		ft_printf("./%s:\n", str);
	else
		opt->r_rep == 1;
	while (*elem->next != NULL)
	{
		if (opt->l == 1)
		{
			ft_checkall_size(elem);
			ft_lprint(elem, opt);
		}
		else
			ft_no_optprint(elem, opt);
		*elem = *elem->next;
	}
	*elem = save;
}
