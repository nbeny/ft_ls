/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:01:25 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/01 16:37:32 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static t_flag	ft_init_f(t_flag f)
{
	int i;

	i = -1;
	f.i = 0;
	f.c = 0;
	f.arg = NULL;
	f.warg = NULL;
	f.sign = 0;
	while (++i < 14)
		f.flag[i] = 0;
	f.size = 0;
	f.x = 0;
	f.p = 0;
	f.free = 0;
	f.wc[0] = 0;
	f.wc[1] = 0;
	f.what = 0;
	return (f);
}

int				ft_fill_stdout(const char *format, va_list *ap)
{
	t_flag	f;
	int		i;

	i = -1;
	g_i = 0;
	ft_bzero(g_buf, 4096);
	while (format[++i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			break ;
		if (format[i] == '%')
		{
			f = ft_init_f(f);
			f.format = (char *)&format[++i];
			if (ft_dispatcher(&f, ap) == -1)
				i--;
			if (f.free == 1)
				free(f.arg);
			i += f.i;
		}
		else
			g_buf[g_i++] = format[i];
	}
	return (g_i);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	ret = ft_fill_stdout(format, &ap);
	va_end(ap);
	ft_putnstr(g_buf, g_i);
	return (ret);
}
