/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zto.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 22:52:14 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/17 10:20:13 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_handler_jo(t_flag *f, va_list *ap)
{
	f->arg = ft_umax_itoa_base((intmax_t)va_arg(*ap, intmax_t), 8);
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

int		ft_handler_zo(t_flag *f, va_list *ap)
{
	f->arg = ft_size_itoa_base((size_t)va_arg(*ap, size_t), 8);
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