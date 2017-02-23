/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flaghhllu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 22:18:59 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/17 10:19:24 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_handler_hhu(t_flag *f, va_list *ap)
{
	f->arg = ft_uchar_itoa_base(
		(unsigned char)va_arg(*ap, unsigned int), 10);
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_int(f));
	f->ret += f->size;
	ft_putstr(f->arg);
	free(f->arg);
	return (0);
}

int		ft_handler_hu(t_flag *f, va_list *ap)
{
	f->arg = ft_ushort_itoa_base(
		(unsigned short int)va_arg(*ap, unsigned int), 10);
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_int(f));
	f->ret += f->size;
	ft_putstr(f->arg);
	free(f->arg);
	return (0);
}

int		ft_handler_llu(t_flag *f, va_list *ap)
{
	f->arg = ft_ullitoa_base(
		(unsigned long long int)va_arg(*ap, unsigned long long int), 10);
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_int(f));
	f->ret += f->size;
	ft_putstr(f->arg);
	free(f->arg);
	return (0);
}

int		ft_handler_lu(t_flag *f, va_list *ap)
{
	f->arg = ft_ulitoa_base(
		(unsigned long int)va_arg(*ap, unsigned long int), 10);
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_int(f));
	f->ret += f->size;
	ft_putstr(f->arg);
	free(f->arg);
	return (0);
}
