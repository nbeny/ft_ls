#include "../include/ft_ls.h"

int		ft_ls(char *str)
{
	struct dirent	*d;
	DIR		*dir;

	if ((dir = opendir(str)) == NULL)
		return (0);
	while ((d = readdir(dir)))
		printf("%s\n", d->d_name);
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
