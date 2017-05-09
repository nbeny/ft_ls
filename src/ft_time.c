/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 01:44:44 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/08 19:01:35 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static char		*ft_build_time(char *st_time, int i, int j)
{
	char	*endtime;
	char	*tmp;
	char	*tmp2;
	char	*space;
	int		z;

	endtime = NULL;
	tmp = ft_strsub(st_time, 4, 7);
	tmp2 = ft_strsub(st_time, i, j);
	space = ft_strjoin(tmp, " ");
	endtime = ft_strjoin(space, tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	ft_strdel(&space);
	z = 0;
	while (endtime[z] != '\0')
	{
		if (endtime[z] == '\n')
			endtime[z] = '\0';
		z++;
	}
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
		endtime = ft_build_time(modtime, 20, 22);
	else
		endtime = ft_strsub(modtime, 4, 12);
	return (endtime);
}

DIR				*ft_dirdir(char *str)
{
	DIR	*dir;

	dir = opendir(str);
	if (dir == NULL)
	{
		perror("ls: No such file or directory\n");
		return (NULL);
	}
	return (dir);
}
