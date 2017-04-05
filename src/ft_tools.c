#include "../include/ft_ls.h"

int		ft_isrep(t_elem *el)
{
	if (S_ISDIR(el->st_mode))
		return (1);
	return (0);
}

char	*ft_newstr(char *str, t_elem *el)
{
	char *tmp;
	char *newstr;

	tmp = NULL;
	if (ft_strcmp(str, "/") != 0)
	{
		tmp = ft_strjoin(str, "/");
		newstr = ft_strjoin(tmp, el->d_name);
		free(tmp);
		tmp = NULL;
	}
	else
		newstr = ft_strjoin(str, el->d_name);
	return (newstr);
}

char	*ft_newstr_inmem(char *str, t_elem *el)
{
	char *tmp;
	char *newstr;

	tmp = NULL;
	if (ft_strcmp(str, "/") != 0)
	{
		tmp = ft_strjoin(str, "/");
		newstr = ft_strjoin(tmp, el->d_name);
		free(tmp);
		tmp = NULL;
	}
	else
		newstr = ft_strjoin(str, el->d_name);
	return (newstr);
}

void		ft_freestyle(t_elem *elem)
{
	t_elem *save;

	while (elem->next != NULL)
	{
		save = elem;
		elem = elem->next;
		free(save);
		save = NULL;
	}
}
