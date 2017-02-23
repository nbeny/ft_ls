/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:59:36 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/21 12:32:38 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_flag_moins(t_flag *f)
{
	int	i;

	if (f->flag[13] == 1 && f->flag[0] < f->size)
	{
		if (f->flag[0] == -1)
			f->flag[0] = 0;
		f->size = f->flag[0];
	}
	i = f->flag[1] - f->size;
	if (f->arg != NULL)
		ft_putnstr(f->arg, f->size);
	else if (f->warg != NULL)
		ft_putnstr((char *)f->warg, f->size);
	f->ret += f->size;
	ft_putcstr(' ', i);
	f->ret += i;
	return (0);
}

static int	ft_flag_plus(t_flag *f)
{
	int	i;

	if (f->flag[13] == 1 && f->flag[0] < f->size)
	{
		if (f->flag[0] == -1 )
			f->flag[0] = 0;
		f->size = f->flag[0];
	}
	i = f->flag[1] - f->size;
	ft_putcstr(' ', i);
	f->ret += i;
	if (f->arg != NULL)
		ft_putnstr(f->arg, f->size);
	else if (f->warg != NULL)
		ft_putnstr((char *)f->warg, f->size);
	f->ret += f->size;
	return (0);
}

static int	ft_flag_zero(t_flag *f)
{
	int	i;

	if (f->flag[13] == 1 && f->flag[0] < f->size)
	{
		if (f->flag[0] == -1)
			f->flag[0] = 0;
		f->size = f->flag[0];
	}
	i = f->flag[1] - f->size;
	ft_putcstr('0', i);
	f->ret += i;
	if (f->arg != NULL)
		ft_putnstr(f->arg, f->size);
	else if (f->warg != NULL)
		ft_putnstr((char *)f->warg, f->size);
	f->ret += f->size;
	return (0);
}

int			ft_flags_char(t_flag *f)
{
	if (f->flag[4] == 1 && f->flag[1] > f->size)
		return (ft_flag_moins(f));
	if (f->flag[3] == 1 && f->flag[1] > f->size)
		return (ft_flag_zero(f));
	if ((f->flag[5] == 1 && f->flag[1] > f->size) ||
		(f->flag[6] == 1 && f->flag[1] > f->size) ||
		f->flag[1] > f->size)
		return (ft_flag_plus(f));
	if (f->flag[13] == 1 && f->flag[0] < f->size && f->c != '%')
	{
		if (f->flag[0] == -1)
			f->flag[0] = 0;
		f->size = f->flag[0];
	}
	if (f->arg != NULL)
		ft_putnstr(f->arg, f->size);
	else if (f->warg != NULL)
		ft_putnstr((char *)f->warg, f->size);
	f->ret += f->size;
	return (f->ret);
}
