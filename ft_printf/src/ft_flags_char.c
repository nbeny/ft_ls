/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:59:36 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/01 16:15:05 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_flag_moins(t_flag *f)
{
	int	i;

	if (f->flag[13] == 1 && f->flag[0] < f->size &&
		f->c != '%' && f->c != 'c' && f->c != 'C' &&
		f->what != 1)
	{
		if (f->flag[0] == -1)
			f->flag[0] = 0;
		f->size = f->flag[0];
	}
	i = f->flag[1] - f->size;
	if (f->size > 0)
	{
		ft_strncpy(&g_buf[g_i], f->arg, f->size);
		g_i += f->size;
	}
	if (i > 0)
	{
		ft_cpynchar(&g_buf[g_i], ' ', i);
		g_i += i;
	}
	return (g_i);
}

static int	ft_flag_plus(t_flag *f)
{
	int	i;

	if (f->flag[13] == 1 && f->flag[0] < f->size &&
		f->c != '%' && f->c != 'c' && f->c != 'C' &&
		f->what != 1)
	{
		if (f->flag[0] == -1)
			f->flag[0] = 0;
		f->size = f->flag[0];
	}
	i = f->flag[1] - f->size;
	if (i > 0)
	{
		ft_cpynchar(&g_buf[g_i], ' ', i);
		g_i += i;
	}
	if (f->size > 0)
	{
		ft_strncpy(&g_buf[g_i], f->arg, f->size);
		g_i += f->size;
	}
	return (g_i);
}

static int	ft_flag_zero(t_flag *f)
{
	int	i;

	if (f->flag[13] == 1 && f->flag[0] < f->size &&
		f->c != '%' && f->c != 'c' && f->c != 'C' &&
		f->what != 1)
	{
		if (f->flag[0] == -1)
			f->flag[0] = 0;
		f->size = f->flag[0];
	}
	i = f->flag[1] - f->size;
	if (i > 0)
	{
		ft_cpynchar(&g_buf[g_i], '0', i);
		g_i += i;
	}
	if (f->size > 0)
	{
		ft_strncpy(&g_buf[g_i], f->arg, f->size);
		g_i += f->size;
	}
	return (g_i);
}

int			ft_flags_char(t_flag *f)
{
	if (f->flag[4] == 1)
		return (ft_flag_moins(f));
	if (f->flag[3] == 1)
		return (ft_flag_zero(f));
	if (f->flag[5] == 1 || f->flag[6] == 1 || f->flag[1] > f->size ||
		(f->flag[1] > f->flag[0] && f->flag[13] == 1 &&
		f->flag[0] < f->size))
		return (ft_flag_plus(f));
	if (f->flag[13] == 1 && f->flag[0] < f->size &&
		f->c != '%' && f->c != 'c' && f->c != 'C' &&
		f->what != 1)
	{
		if (f->flag[0] == -1)
			f->flag[0] = 0;
		f->size = f->flag[0];
	}
	ft_strncpy(&g_buf[g_i], f->arg, f->size);
	g_i += f->size;
	return (g_i);
}
