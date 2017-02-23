/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:01:02 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/17 06:19:25 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_handler_ws(t_flag *f, va_list *ap)
{
	int i;

	i = 0;
	f->warg = va_arg(*ap, wchar_t *);
	while (f->warg[i])
	{
		if (f->warg[i] < 0 && f->warg[i] > 55295 &&
			f->warg[0] < 57344 && f->warg[i] > 1114111)
		{
			f->ret = -1;
			return (-1);
		}
		i++;
	}
	f->size = i;
	if (f->warg == NULL)
	{
		f->arg = ft_strdup("(null)");
		f->free = 1;
	}
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_char(f));
	f->ret += f->size;
	ft_putstr((char *)f->warg);
	return (0);
}

int	ft_handler_s(t_flag *f, va_list *ap)
{
	if (f->flag[10] == 1)
		return (ft_handler_ws(f, ap));
	f->arg = va_arg(*ap, char *);
	f->size = ft_strlen(f->arg);
	if (f->arg == NULL)
	{
		f->arg = ft_strdup("(null)");
		f->free = 1;
	}
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_char(f));
	f->ret += f->size;
	ft_putstr(f->arg);
	return (0);
}
