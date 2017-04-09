#include "../include/ft_ls.h"

static char		*ft_build_time(char *st_time, int i, int j)
{
	char *endtime;
	char *tmp;
	char *tmp2;

	tmp = ft_strsub(st_time, 4, 7);
	tmp2 = ft_strsub(st_time, i, j);
	endtime = ft_strjoin(tmp, tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (endtime);
}

char			*ft_set_time(time_t st_tim)
{
	time_t	yet;
	char	*endtime;
	char	*modtime;

	yet = time(NULL);
	modtime = ctime(&st_tim);
	endtime = NULL;
	if ((yet - st_tim) >= 15778800 || (yet - st_tim) < 0)
	{
		if (ft_strcmp(&modtime[23], " 10000\n"))
			endtime = ft_build_time(modtime, 6, 23);
		else
			endtime = ft_build_time(modtime, 5, 19);
	}
	else
		endtime = ft_strsub(modtime, 4, 12);
	return (endtime);
}
