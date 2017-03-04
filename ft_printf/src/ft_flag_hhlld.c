/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hhlld.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 21:08:51 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/27 21:26:30 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_handler_hhd(t_flag *f, va_list *ap)
{
	f->arg = ft_char_itoa_base((signed char)va_arg(*ap, int), 10);
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_int(f));
	ft_strncpy(&g_buf[g_i], f->arg, f->size);
	g_i += f->size;
	free(f->arg);
	return (0);
}

int		ft_handler_hd(t_flag *f, va_list *ap)
{
	f->arg = ft_short_itoa_base((short int)va_arg(*ap, int), 10);
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_int(f));
	ft_strncpy(&g_buf[g_i], f->arg, f->size);
	g_i += f->size;
	if (f->arg[0] != '0')
		free(f->arg);
	return (0);
}

int		ft_handler_lld(t_flag *f, va_list *ap)
{
	f->arg = ft_llitoa_base((long long int)va_arg(*ap, long long int), 10);
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_int(f));
	ft_strncpy(&g_buf[g_i], f->arg, f->size);
	g_i += f->size;
	free(f->arg);
	return (0);
}

int		ft_handler_ld(t_flag *f, va_list *ap)
{
	f->arg = ft_litoa_base((long int)va_arg(*ap, long int), 10);
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_int(f));
	ft_strncpy(&g_buf[g_i], f->arg, f->size);
	g_i += f->size;
	free(f->arg);
	return (0);
}
