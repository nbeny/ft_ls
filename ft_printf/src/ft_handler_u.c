/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 22:14:33 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/17 10:21:31 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_modifier_u(t_flag *f, va_list *ap)
{
	if (f->flag[7] == 1)
		return (ft_handler_hhu(f, ap));
	if (f->flag[8] == 1)
		return (ft_handler_hu(f, ap));
	if (f->flag[9] == 1)
		return (ft_handler_llu(f, ap));
	if (f->flag[10] == 1)
		return (ft_handler_lu(f, ap));
	if (f->flag[11] == 1)
		return (ft_handler_ju(f, ap));
	if (f->flag[12] == 1)
		return (ft_handler_zu(f, ap));
	return (0);
}

int	ft_handler_wu(t_flag *f, va_list *ap)
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

int	ft_handler_u(t_flag *f, va_list *ap)
{
	if (f->flag[7] == 1 || f->flag[8] == 1 ||
		f->flag[9] == 1 || f->flag[10] == 1 ||
		f->flag[11] == 1 || f->flag[12] == 1)
		return (ft_modifier_u(f, ap));
	f->arg = ft_uitoa_base((unsigned int)va_arg(*ap, unsigned int), 10);
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
