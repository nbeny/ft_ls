#include "../include/ft_ls.h"

t_opt	ft_init_opt(t_opt opt)
{
	opt.r = 0;
	opt.up_g = 0;
	opt.a = 0;
	opt.up_a = 0;
	opt.up_u = 0;
	opt.up_f = 0;
	opt.l = 0;
	opt.up_r = 0;
	return (opt);
}

int		ft_ls(char *str)
{
	struct dirent	*d;
	struct stat		stat;
	t_elem				*elem;
	DIR				*dir;

	if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
	{
		perror("error ! unable to malloc structure elem.\n");
		exit(EXIT_FAILURE);
	}
	dir = opendir(str);
	if (dir == NULL)
	{
		perror("Error ! Unable to open directory.\n");
		exit(EXIT_FAILURE);
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
	int			i[2];
	t_opt			opt;

	i[0] = 0;
	i[1] = 1;
	opt = ft_init_opt(opt);
	if (ac == 1)
		ft_ls(".");
	while (av[++i[0]] != NULL)
	{
		if (av[i[0]][0] == '-')
		{
			ft_check_opt(av[i[0]], &opt);
			i[1] += 1;
		}
		else
			ft_ls(av[i[0]]);
	}
	printf("[%i][%i]\n", i[0], i[1]);
	if (i[1] == i[0] && ac != 1)
		ft_ls(".");
	return (0);
}
