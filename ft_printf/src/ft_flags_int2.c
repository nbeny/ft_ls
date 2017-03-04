/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_int2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:51:13 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/01 16:38:57 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_flags_zero2(t_flag *f, int i)
{
	if (f->arg[0] == '-')
	{
		f->arg = ft_rotcstring(f->arg);
		ft_cpynchar(&g_buf[g_i], '-', 1);
		g_i += 1;
		f->size -= 1;
	}
	if (f->flag[2] == 1)
	{
		if ((f->arg[0] != '0' || f->c == 'p') && f->flag[0] != -1)
		{
			ft_strncpy(&g_buf[g_i], f->ox, f->x);
			g_i += f->x;
		}
	}
	if (i > 0)
	{
		ft_cpynchar(&g_buf[g_i], '0', i);
		g_i += i;
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	return (0);
}

int		ft_flags_moins2(t_flag *f)
{
	if (f->flag[2] == 1)
	{
		if ((f->arg[0] != '0' || f->c == 'p') && f->flag[0] != -1)
		{
			ft_strncpy(&g_buf[g_i], f->ox, f->x);
			g_i += f->x;
		}
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	if (f->flag[13] == 1 && f->p > 0)
	{
		ft_cpynchar(&g_buf[g_i], '0', f->p);
		g_i += f->p;
	}
	if (f->flag[0] != -1)
	{
		ft_strncpy(&g_buf[g_i], f->arg, f->size);
		g_i += f->size;
		free(f->arg);
	}
	return (0);
}

int		ft_flags_plus2(t_flag *f)
{
	if (f->flag[2] == 1)
	{
		if ((f->arg[0] != '0' || f->c == 'p') && f->flag[0] != -1)
		{
			ft_strncpy(&g_buf[g_i], f->ox, f->x);
			g_i += f->x;
		}
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	if (f->flag[13] == 1 && f->p > 0)
	{
		ft_cpynchar(&g_buf[g_i], '0', f->p);
		g_i += f->p;
	}
	ft_flags_int3(f);
	return (0);
}

int		ft_flags_plus3(t_flag *f)
{
	if (f->flag[0] != -1)
	{
		if (f->c == 'd' && f->format[f->i - 1] == ' ' &&
			f->format[f->i - 2] == '%' && f->arg[0] != '-')
		{
			ft_cpynchar(&g_buf[g_i], ' ', 1);
			g_i += 1;
		}
		ft_strncpy(&g_buf[g_i], f->arg, f->size);
		g_i += f->size;
		free(f->arg);
	}
	return (0);
}

int		ft_flags_int2(t_flag *f)
{
	if (f->arg[0] == '-' && f->flag[13] == 1)
	{
		f->arg = ft_rotcstring(f->arg);
		ft_cpynchar(&g_buf[g_i], '-', 1);
		f->p += 1;
		g_i += 1;
	}
	if (f->flag[2] == 1)
	{
		if ((f->arg[0] != '0' && f->flag[0] != -1) ||
			f->c == 'p' || f->c == 'o')
		{
			ft_strncpy(&g_buf[g_i], f->ox, f->x);
			g_i += f->x;
		}
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	ft_flags_int3(f);
	return (0);
}
