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
	fprintf(*elem.st_mode & S_IXUSR ? 'x' : '-');
	fprintf(*elem.st_mode & S_IRGRP ? 'r' : '-');
	fprintf(*elem.st_mode & S_IWGRP ? 'w' : '-');
	fprintf(*elem.st_mode & S_IXGRP ? 'x' : '-');
	fprintf(*elem.st_mode & S_IROTH ? 'r' : '-');
	fprintf(*elem.st_mode & S_IWOTH ? 'w' : '-');
	fprintf(*elem.st_mode & S_IXOTH ? 'x' : '-');
	fprintf(stderr,"\t%hu",status.st_nlink);

	if ((pwd = getpwuid(status.st_uid)) != NULL)
		fprintf(stderr,"\t%s", pwd->pw_name);
	if ((grp = getgrgid(status.st_gid)) != NULL)
		fprintf(stderr,"\t%s", grp->gr_name);

	fprintf(stderr,"\t%lld",status.st_size);
	fflush(stdin);
	fprintf(stderr,"\t%-24.24s\t",ctime(&status.st_mtime));
	fflush(stdin);

	if((ptdir=opendir(nom)) != NULL)
		{
			couleur("34" );
			fprintf(stderr,"%s\n",nom);
			couleur("0" );
		}
	else if (S_ISREG(status.st_mode ) && status.st_mode & 0111)
		{
			couleur("32" );
			fprintf(stderr,"%s\n",nom);
			couleur("0" );
		}
	/* ((status.st_mode & S_IFMT) != S_IFREG) : .exe */

	else
		fprintf(stderr,"%s\n",nom);
}

void	ft_no_optprint(t_elem **elem, t_opt *opt)
{
	if (*elem->d_name[0] != '.' || opt->a == 1 ||
		(opt->up_a == 1 && (*elem->d_name[0] != '.' &&
		*elem->d_name[1] != '\0') || (*elem->d_name[0] != '.' &&
		*elem->d_name[1] != '.' && *elem->d_name[2] != '\0'))
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
			ft_lprint(elem, opt);
		else
			ft_no_optprint(elem, opt);
		*elem = *elem->next;
	}
	*elem = save;
}
