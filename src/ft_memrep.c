#include "../include/ft_ls.h"

int	ft_memrep(struct dirent *d, struct stat stat, DIR *dir, t_elem *elem)
{
	t_elem *save;

	while ((d = readdir(dir)) != NULL)
	{
		if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
		{
			perror("error ! unable to malloc structure elem.\n");
			exit(EXIT_FAILURE);
		}
	}
	save = elem;
	elem.name = stat.name;
}
