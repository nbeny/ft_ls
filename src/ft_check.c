#include "../include/ft_ls.h"

int		ft_check_opt(char *str, t_opt *opt)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'r')
			opt->r = 1;
		if (str[i] == 'G')
			opt->up_g = 1;
		if (str[i] == 'a')
			opt->a = 1;
		if (str[i] == 'A')
			opt->up_a = 1;
		if (str[i] == 'U')
			opt->up_u = 1;
		if (str[i] == 'F')
			opt->up_f = 1;
		if (str[i] == 'l')
			opt->l = 1;
		if (str[i] == 'R')
			opt->up_r = 1;
		i++;
	}
	return (i);
}
