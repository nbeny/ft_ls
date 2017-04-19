/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 01:43:59 by nbeny             #+#    #+#             */
/*   Updated: 2017/04/12 01:44:02 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	ft_check_error(void)
{
	perror("ls: illegal option --\n"
		"usage: ls [-ARafglnortu] [file ...]\n");
	exit(EXIT_FAILURE);
}

void		ft_check_bonus(char *str, t_opt *opt, int i)
{
	if (str[i] == 'g')
	{
		opt->g = 1;
		opt->l = 1;
	}
	else if (str[i] == 'n')
	{
		opt->n = 1;
		opt->l = 1;
	}
	else if (str[i] == 'o')
	{
		opt->o = 1;
		opt->l = 1;
	}
}

int		ft_getopt(char *str, t_opt *opt, int i)
{
	if (str[i] == 'g' || str[i] == 'n' || str[i] == 'o')
		ft_check_bonus(str, opt, i);
	else if (str[i] == 'R')
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

	i = 1;
	while (str[i])
	{
		ft_getopt(str, opt, i);
		i++;
	}
	return (i);
}

void	ft_check_str(char *str, t_opt *opt)
{
	if (opt->up_r == 1 && opt->r_rep == 1 &&
	    (ft_strncmp(str, ".\0", 2) || ft_strncmp(str, "/\0", 2)))
		ft_printf("\n%s:\n", str);
	else if (opt->up_r == 1 && opt->r_rep == 1)
		ft_printf("\n%s:\n", str);
	else if (opt->isarg[0] == 1)
	{
		if (opt->isarg[1] == 1)
			ft_putchar('\n');
		ft_printf("%s:\n", str);
		opt->isarg[1] = 1;
	}
	else
		opt->r_rep = 1;
}
