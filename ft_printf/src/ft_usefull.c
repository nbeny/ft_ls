/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usefull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:33:41 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/01 16:43:30 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_cpynchar(char *dest, int c, size_t n)
{
	unsigned int i;

	i = 0;
	if (dest)
	{
		while (i < n)
		{
			dest[i] = c;
			i++;
		}
	}
	return (dest);
}

int		ft_putwchar_in_char(wchar_t wchar, char *fresh, int i)
{
	int		size;

	size = ft_wcharlen(wchar);
	if (size == 1)
		fresh[i++] = wchar;
	else if (size == 2)
	{
		fresh[i++] = (wchar >> 6) + 0xC0;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	else if (size == 3)
	{
		fresh[i++] = (wchar >> 12) + 0xE0;
		fresh[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	else
	{
		fresh[i++] = (wchar >> 18) + 0xF0;
		fresh[i++] = ((wchar >> 12) & 0x3F) + 0x80;
		fresh[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	return (i);
}

void	ft_wint_to_char(wint_t wchar, t_flag *f)
{
	if (!wchar)
	{
		if (f->flag[1] > 0)
			f->flag[1]--;
		f->arg = ft_strdup("\0");
	}
	else
	{
		f->arg = ft_strnew(ft_wbytelen(&wchar));
		ft_putwchar_in_char(wchar, f->arg, 0);
	}
}

char	*ft_transform_wchar_in_char(wchar_t *ws)
{
	char	*fresh;
	int		i;
	int		k;
	int		len;

	if (!ws)
		return (0);
	i = 0;
	k = 0;
	len = ft_wbytelen(ws);
	fresh = (char*)malloc(sizeof(char) * len);
	fresh[len] = '\0';
	while (ws[k])
	{
		i = ft_putwchar_in_char(ws[k], fresh, i);
		k++;
	}
	return (fresh);
}

int		ft_special(t_flag *f)
{
	ft_cpynchar(&g_buf[g_i], ' ', 1);
	g_i += 1;
	ft_strncpy(&g_buf[g_i], f->arg, f->size);
	g_i += f->size;
	return (g_i);
}
