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
