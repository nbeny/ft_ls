#include "../include/ft_ls.h"

static char		*build_time(char *dtime, int st, int ed)
{
	char *ntime;
	char *tmp;
	char *tmpt;

	tmp = ft_strsub(dtime, 4, 7);
	tmpt = ft_strsub(dtime, st, ed);
	ntime = ft_strjoin(tmp, tmpt);
	ft_strdel(&tmp);
	ft_strdel(&tmpt);
	return (ntime);
}

char			*set_time(time_t timef)
{
	time_t	now;
	char	*ntime;
	char	*dtime;

	now = time(NULL);
	dtime = ctime(&timef);
	ntime = NULL;
	if ((now - timef) >= 15778800 || (now - timef) < 0)
	{
		if (ft_strcmp(&dtime[23], " 10000\n") == 0)
			ntime = build_time(dtime, 23, 6);
		else
			ntime = build_time(dtime, 19, 5);
	}
	else
		ntime = ft_strsub(dtime, 4, 12);
	return (ntime);
}
