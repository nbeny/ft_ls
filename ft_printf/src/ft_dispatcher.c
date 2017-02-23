/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:58:13 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/17 08:00:21 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_init_specs2(t_spec *specs)
{
	specs[10].c = 'x';
	specs[10].ptr = &ft_handler_x;
	specs[11].c = 'X';
	specs[11].ptr = &ft_handler_wx;
	specs[12].c = 'c';
	specs[12].ptr = &ft_handler_c;
	specs[13].c = 'C';
	specs[13].ptr = &ft_handler_wc;
	specs[14].c = '%';
	specs[14].ptr = &ft_handler;
	specs[15].c = 0;
	specs[15].ptr = NULL;
}

void	ft_init_specs1(t_spec *specs)
{
	specs[0].c = 's';
	specs[0].ptr = &ft_handler_s;
	specs[1].c = 'S';
	specs[1].ptr = &ft_handler_ws;
	specs[2].c = 'p';
	specs[2].ptr = &ft_handler_p;
	specs[3].c = 'd';
	specs[3].ptr = &ft_handler_d;
	specs[4].c = 'D';
	specs[4].ptr = &ft_handler_wd;
	specs[5].c = 'i';
	specs[5].ptr = &ft_handler_d;
	specs[6].c = 'o';
	specs[6].ptr = &ft_handler_o;
	specs[7].c = 'O';
	specs[7].ptr = &ft_handler_wo;
	specs[8].c = 'u';
	specs[8].ptr = &ft_handler_u;
	specs[9].c = 'U';
	specs[9].ptr = &ft_handler_wu;
	ft_init_specs2(specs);
}

int		ft_dispatcher(t_flag *f, va_list *ap)
{
	t_spec	specs[16];
	int		j;

	f->arg = NULL;
	f->warg = NULL;
	if (ft_check(f) == -1)
		return (-1);
	ft_init_specs1(specs);
	f->c = f->format[f->i];
	j = 0;
	while (specs[j].c != f->c && specs[j].c != 0)
		j++;
	if (specs[j].c == 0)
		return (0);
	if (j == 14)
		return (specs[14].ptr(f));
	return (specs[j].ptr(f, ap));
}
