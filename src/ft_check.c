#include "../include/ft_ls.h"

void	ft_check_error(void)
{
	perror("ls: illegal option --\n");
	perror("usage: ls [-RlrftuG] [file ...]\n");
	exit(EXIT_FAILURE);	
}

int		ft_getopt(char *str, t_opt *opt, int i)
{
	if (str[i] == 'R')
		opt->up_r = 1;
	else if (str[i] == 'l')
		opt->l = 1;
	else if (str[i] == 'r')
		opt->r = 1;
	else if (str[i] == 'f')
		opt->f = 1;
	else if (str[i] == 't')
		opt->t = 1;
	else if (str[i] == 'u')
		opt->u = 1;
	else if (str[i] == 'G')
		opt->up_g = 1;
	else if (str[i] == 'a')
		opt->a = 1;
	else if (str[i] == 'A')
		opt->up_a = 1;
	else
		ft_check_error();
	return (0);
}

int		ft_check_opt(char *str, t_opt *opt)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_getopt(str, opt, i);
		i++;
	}
	return (i);
}
