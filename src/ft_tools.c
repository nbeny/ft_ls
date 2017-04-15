/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 01:44:55 by nbeny             #+#    #+#             */
/*   Updated: 2017/04/12 01:44:57 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		ft_freestyle(t_elem *elem, char *str)
{
	t_elem *save;

	ft_strdel(&str);
	while (elem->next != NULL)
	{
		ft_strdel(&(elem->d_name));
		if (S_ISLNK(elem->st_mode))
			ft_strdel(&(elem->lk_name));
		ft_strdel(&(elem->pw_name));
		ft_strdel(&(elem->gr_name));
		ft_strdel(&(elem->atime_c));
		ft_strdel(&(elem->mtime_c));
		save = elem;
		elem = elem->next;
		free(save);
		save = NULL;
	}
}
