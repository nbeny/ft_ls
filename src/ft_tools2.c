#include "../include/ft_ls.h"

t_elem	*ft_first_source(void)
{
	DIR			*dir;
	struct dirent	*d;
	struct stat	st;
	t_elem		*elem;

	dir = opendir("/");
	if (dir == NULL)
	{
		perror("ls : No such file or directory\n");
		exit(EXIT_FAILURE);
	}
	d = readdir(dir);
	if (d == NULL)
	{
		perror("error ! Unable to read file.\n");
		exit(EXIT_FAILURE);
	}
	if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
	{
		perror("error ! Unable to malloc structure elem.\n");
		exit(EXIT_FAILURE);
	}
	elem->d_name = ft_strdup(d->d_name);
	if (lstat(elem->d_name, &st) == -1)
	{
		perror("error ! Unable to malloc structure elem.\n");
		exit(EXIT_FAILURE);
	}
	elem = ft_getstat(elem, elem->d_name);
	elem = ft_lstcpy_inelem(elem);
	closedir(dir);
	return (elem);
}

void		ft_free_arg(t_elem *elem)
{
	t_elem *save;

	while (elem != NULL)
	{
		if (S_ISLNK(elem->st_mode))
			ft_strdel(&(elem->lk_name));
		ft_strdel(&(elem->pw_name));
		ft_strdel(&(elem->gr_name));
		ft_strdel(&(elem->atime_c));
		ft_strdel(&(elem->mtime_c));
		save = elem;
		elem = elem->next;
		free(save);
		save = NULL;
	}
}

t_elem		*ft_free_firstone(t_elem *elem)
{
	t_elem	*sa;

	sa = elem;
	elem = elem->next;
	ft_strdel(&(sa->d_name));
	if (S_ISLNK(sa->st_mode))
		ft_strdel(&(sa->lk_name));
	ft_strdel(&(sa->pw_name));
	ft_strdel(&(sa->gr_name));
	ft_strdel(&(sa->atime_c));
	ft_strdel(&(sa->mtime_c));
	free(sa);
	sa = NULL;
	return (elem);
}
