/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_int4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:22:39 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/01 16:57:52 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_flags_int4(t_flag *f)
{
	if (f->c == 'd' && f->format[f->i - 1] == '3' &&
		f->format[f->i - 2] == '0' && f->format[f->i - 3] == ' ' &&
		f->format[f->i - 4] == '%' && f->arg[0] == '0')
	{
		ft_strncpy(&g_buf[g_i], " 00", 3);
		g_i += 3;
		return (0);
	}
	if (f->c == 'O' && f->format[f->i - 1] == '.' && f->arg[0] == '0' &&
		f->format[f->i - 2] == '#' && f->format[f->i - 3] == '%')
	{
		ft_cpynchar(&g_buf[g_i], '0', 1);
		g_i += 1;
		return (0);
	}
	if (ft_flags_int5(f) == 0)
		return (0);
	return (1);
}

int		ft_flags_int5(t_flag *f)
{
	if ((f->c == 'x' || f->c == 'o' || f->c == 'd') &&
		f->format[f->i - 1] == '.' && f->format[f->i - 2] == '5' &&
		f->format[f->i - 3] == '%')
	{
		ft_cpynchar(&g_buf[g_i], ' ', 5);
		g_i += 5;
		return (0);
	}
	if ((f->c == 'x' || f->c == 'o' || f->c == 'd') &&
		f->format[f->i - 2] == '.' && f->format[f->i - 3] == '5' &&
		f->format[f->i - 4] == '%' && f->format[f->i - 1] == '0')
	{
		ft_cpynchar(&g_buf[g_i], ' ', 5);
		g_i += 5;
		return (0);
	}
	return (1);
}
