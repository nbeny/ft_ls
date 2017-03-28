#include "../include/ft_ls.h"

t_elem	*ft_memrep(struct dirent *d, DIR *dir)
{
	struct stat	stat;
	t_elem		*save;

	d = readdir(dir);
	if (d = NULL)
	{
		perror("error ! Unable to read files.\n");
		exit(EXIT_FAILURE);
	}
	if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
	{
		perror("error ! unable to malloc first structure elem.\n");
		exit(EXIT_FAILURE);
	}
	if (stat(d->d_name, &stat) == -1)
	{
		perror("error stat fonction !\n");
		exite(EXIT_FAILURE);
	}
	elem = ft_lstcpy_inelem(&stat);
	save = elem;
	while ((d = readdir(dir)) != NULL)
	{
		if (d = NULL)
		{
			perror("error ! Unable to read files.\n");
			exit(EXIT_FAILURE);
		}
		if (!(elem->next = (t_elem *)malloc(sizeof(t_elem))))
		{
			perror("error ! unable to malloc structures elems.\n");
			exit(EXIT_FAILURE);
		}
		elem = elem->next;
		d = readdir(dir);
		if (d = NULL)
		{
			perror("error ! Unable to read files.\n");
			exit(EXIT_FAILURE);
		}
		if (stat(d->d_name, &stat) == -1)
		{
			perror("error stat fonction !\n");
			exite(EXIT_FAILURE);
		}
		elem = ft_lstcpy_inelem(&stat);
	}
	elem->next = NULL;
	elem = save;
	return (elem);
}
