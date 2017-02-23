/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 22:35:26 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/17 10:21:39 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_modifier_x(t_flag *f, va_list *ap)
{
	if (f->flag[7] == 1)
		return (ft_handler_hhx(f, ap));
	if (f->flag[8] == 1)
		return (ft_handler_hx(f, ap));
	if (f->flag[9] == 1)
		return (ft_handler_llx(f, ap));
	if (f->flag[10] == 1)
		return (ft_handler_lx(f, ap));
	if (f->flag[11] == 1)
		return (ft_handler_jx(f, ap));
	if (f->flag[12] == 1)
		return (ft_handler_zx(f, ap));
	return (0);
}

int		ft_handler_wx(t_flag *f, va_list *ap)
{
	if (f->flag[9] == 1)
		return(ft_modifier_x(f, ap));
	f->arg = ft_uitoa_base((unsigned int)va_arg(*ap, unsigned int), 16);
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_int(f));
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	f->ret += f->size;
	ft_putstr(f->arg);
	free(f->arg);
	return (0);
}

int		ft_handler_x(t_flag *f, va_list *ap)
{
	if (f->flag[7] == 1 || f->flag[8] == 1 ||
		f->flag[9] == 1 || f->flag[10] == 1 ||
		f->flag[11] == 1 || f->flag[12] == 1)
		return (ft_modifier_x(f, ap));
	f->arg = ft_uitoa_base((unsigned int)va_arg(*ap, unsigned int), 16);
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_int(f));
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	f->ret += f->size;
	ft_putstr(f->arg);
	free(f->arg);
	return (0);
}
