#include "../include/ft_ls.h"

int		ft_isrep(t_elem *el)
{
	if (el->st_mode == S_IFDIR)
		return (1);
	return (0);
}

char	*ft_newstr(char *str, t_elem *el)
{
	char *tmp;
	char *newstr;

	tmp = ft_strjoin(str, "/");
	newstr = ft_strjoin(tmp, el->d_name);
	free(tmp);
	tmp = NULL;
	return (newstr);
}

char	*ft_newstr_inmem(char *str, t_elem *el)
{
	char *tmp;
	char *newstr;

	tmp = ft_strjoin(str, "/");
	newstr = ft_strjoin(tmp, el->d_name);
	free(tmp);
	tmp = NULL;
	return (newstr);
}

void		ft_freestyle(t_elem *elem)
{
	t_elem *save;

	while (elem != NULL)
	{
		save = elem;
		elem = elem->next;
		free(save);
		save = NULL;
	}
	free(save);
	save = NULL;
}
