#include "../include/ft_ls.h"

t_elem	*ft_lstcpy_inelem(struct stat *stat, t_elem *elem)
{
	elem->st_dev = stat->st_dev;
	elem->st_mode = stat->st_mode;
	elem->st_nlink = stat->st_nlink;
	elem->st_uid = stat->st_uid;
	elem->st_gid = stat->st_gid;
	elem->st_rdev = stat->st_rdev;
	elem->st_atimespec = stat->st_atimespec;
	elem->st_mtimespec = stat->st_mtimespec;
	elem->st_ctimespec = stat->st_ctimespec;
	elem->st_birthtimespec = stat->st_birthtimespec;
	elem->st_size = stat->st_size;
	elem->st_blocks = stat->st_blocks;
	return (elem);
}

t_elem	*ft_getstat(struct dirent *d, struct stat *stat, t_elem **elem)
{
	t_elem *elem;

	if (d = NULL)
	{
		perror("error ! Unable to read files.\n");
		exit(EXIT_FAILURE);
	}
	if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
	{
		perror("error ! unable to malloc structures elems.\n");
		exit(EXIT_FAILURE);
	}
	if (stat(d->d_name, stat) == -1)
	{
		perror("error stat fonction !\n");
		exite(EXIT_FAILURE);
	}
	elem = ft_lstcpy_inelem(stat);
	return (elem);
}

void	ft_memrep(struct dirent *d, DIR *dir)
{
	struct stat	stat;
	t_elem		*elem;
	t_elem		*save;

	d = readdir(dir);
	elem = ft_getstat(d, &stat);
	save = elem;
	while ((d = readdir(dir)) != NULL)
	{
		elem = elem->next;
		elem = ft_getstat(d, &stat);
	}
	elem->next = NULL;
	elem = save;
	return (elem);
}
