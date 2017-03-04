/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:00:03 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/27 18:24:23 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_handler(t_flag *f)
{
	char s[2];

	s[0] = '%';
	s[1] = 0;
	f->arg = s;
	f->size = 1;
	if (f->flag[2] == 1 || f->flag[3] == 1 ||
		f->flag[4] == 1 || f->flag[5] == 1 ||
		f->flag[6] == 1 || f->flag[1] > ft_strlen(f->arg) ||
		f->flag[13] == 1)
		return (ft_flags_char(f));
	ft_strncpy(&g_buf[g_i], f->arg, f->size);
	g_i += f->size;
	return (0);
}
