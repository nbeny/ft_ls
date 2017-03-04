#include "../include/ft_ls.h"

int		ft_ls(char *str)
{
	struct dirent	*d;
	struct stat		stat;
	DIR				*dir;

	dir = opendir(str);
	if (dir == NULL)
	{
		printf("Error ! Unable to open directory.\n");
		exit(1);
	}
	while ((d = readdir(dir)) != NULL)
	{
		printf("%s\n", d->d_name);
	}
	if (S_ISDIR(stat.st_mode))
		ft_ls(d->d_name);
	closedir(dir);
	return (0);
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	(void)ac;
	if (av[1] == NULL)
		ft_ls(".");
	while (av[++i] != NULL)
		ft_ls(av[i]);
	return (0);
}
