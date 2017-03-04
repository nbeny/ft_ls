/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:01:02 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/27 19:51:05 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_norme_ws(t_flag *f)
{
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_char(f));
	ft_strncpy(&g_buf[g_i], f->arg, f->size);
	g_i += f->size;
	return (0);
}

static int	ft_handler_ws_null(t_flag *f)
{
	f->arg = ft_strdup("(null)");
	f->free = 1;
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_char(f));
	ft_strncpy(&g_buf[g_i], f->arg, f->size);
	g_i += f->size;
	return (0);
}

int			ft_handler_ws(t_flag *f, va_list *ap)
{
	int i;

	i = 0;
	f->warg = va_arg(*ap, wchar_t *);
	if (f->warg == NULL)
		return (ft_handler_ws_null(f));
	f->arg = ft_transform_wchar_in_char(f->warg);
	f->free = 1;
	f->size = ft_strlen(f->arg);
	ft_norme_ws(f);
	return (0);
}

int			ft_handler_s(t_flag *f, va_list *ap)
{
	if (f->flag[10] == 1)
		return (ft_handler_ws(f, ap));
	f->arg = va_arg(*ap, char *);
	if (f->arg == NULL)
	{
		f->arg = ft_strdup("(null)");
		f->free = 1;
	}
	f->size = ft_strlen(f->arg);
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_char(f));
	ft_strncpy(&g_buf[g_i], f->arg, f->size);
	g_i += f->size;
	return (0);
}
