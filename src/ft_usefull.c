#include "../include/ft_ls.h"

int		ft_isrep(t_elem **el)
{
	if (*el->st_mode == S_IFDIR)
		return (1);
	return (0);
}

char	*ft_newstr(char *str, t_elem *el)
{
	char *tmp;
	char *newstr;

	tmp = ft_strjoin(str, "/");
	newstr = ft_strjoin(tmp, *elem->d_name);
	free(tmp);
	return (newstr);
}
