#include "../include/ft_ls.h"

int		ft_isrep(t_elem **el)
{
	if (*el->st_mode == S_IFDIR)
		return (1);
	return (0);
}
