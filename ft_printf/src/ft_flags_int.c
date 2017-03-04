/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:59:46 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/01 16:05:58 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_flag_ox(t_flag *f)
{
	int i;

	i = 0;
	ft_bzero(f->ox, 3);
	if (((f->c == 'o' || f->c == 'O' || f->c == 'x' ||
		f->c == 'X') && f->arg[0] != '0') || f->c == 'p')
	{
		f->ox[0] = '0';
		i++;
	}
	if ((f->c == 'x' && f->arg[0] != '0') || f->c == 'p')
	{
		f->ox[1] = 'x';
		i++;
	}
	if (f->c == 'X' && f->arg[0] != '0')
	{
		f->ox[1] = 'X';
		i++;
	}
	f->ox[2] = 0;
	return (i);
}

static int	ft_flag_zero(t_flag *f)
{
	int i;

	i = f->flag[1] - f->size - f->p;
	if (f->flag[2] == 1 && (f->arg[0] != '0' || f->c == 'p'))
		i = i - f->x;
	if (f->flag[5] == 1 && f->arg[0] != '-' &&
		(f->c == 'd' || f->c == 'D' || f->c == 'i'))
	{
		ft_cpynchar(&g_buf[g_i], '+', 1);
		g_i += 1;
		i--;
	}
	ft_flags_zero2(f, i);
	if (f->flag[0] != -1)
	{
		ft_strncpy(&g_buf[g_i], f->arg, f->size);
		g_i += f->size;
		free(f->arg);
	}
	return (0);
}

static int	ft_flag_moins(t_flag *f)
{
	int i;

	i = f->flag[1] - f->size - f->p;
	if (f->flag[2] == 1 && (f->arg[0] != '0' || f->c == 'p'))
		i = i - f->x;
	if (f->flag[5] == 1 && f->arg[0] != '-' &&
		(f->c == 'd' || f->c == 'D' || f->c == 'i'))
	{
		ft_cpynchar(&g_buf[g_i], '+', 1);
		g_i += 1;
		i--;
	}
	if (f->arg[0] == '-')
	{
		f->arg = ft_rotcstring(f->arg);
		ft_cpynchar(&g_buf[g_i], '-', 1);
		g_i += 1;
		f->size -= 1;
		f->p += 1;
	}
	ft_flags_moins2(f);
	ft_flags_moins3(i);
	return (0);
}

static int	ft_flag_plus(t_flag *f)
{
	int i;

	i = f->flag[1] - f->size - f->p;
	if (f->flag[2] == 1 && (f->arg[0] != '0' || f->c == 'p'))
		i = i - f->x;
	if (f->flag[5] == 1 && f->arg[0] != '-')
		i--;
	if (f->flag[0] >= f->size && f->flag[13] == 1 &&
		f->arg[0] == '-')
		i--;
	if (i > 0)
	{
		ft_cpynchar(&g_buf[g_i], ' ', i);
		g_i += i;
	}
	if (f->flag[5] == 1 && f->arg[0] != '-' &&
		(f->c == 'd' || f->c == 'D' || f->c == 'i'))
	{
		ft_cpynchar(&g_buf[g_i], '+', 1);
		g_i += 1;
	}
	return (ft_flags_int2(f));
}

int			ft_flags_int(t_flag *f)
{
	if (ft_flags_int1(f) == 0)
		return (0);
	if (f->flag[2] == 1)
		f->x = ft_flag_ox(f);
	if (f->flag[13] == 1)
		ft_precision(f);
	if (f->flag[4] == 1)
		return (ft_flag_moins(f));
	if (f->flag[3] == 1)
		return (ft_flag_zero(f));
	if (f->flag[5] == 1 || f->flag[6] == 1 ||
		f->flag[1] > ft_strlen(f->arg))
		return (ft_flag_plus(f));
	ft_flags_int2(f);
	return (0);
}
