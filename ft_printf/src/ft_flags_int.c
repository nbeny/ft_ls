/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:59:46 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/21 14:55:17 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_flag_Ox(t_flag *f)
{
	int i;

	i = 0;
	if (!(f->Ox = (char *)malloc(sizeof(char) * 3)))
		return (0);
	ft_bzero(f->Ox, 3);
	if (f->c == 'o' || f->c == 'O' ||
		f->c == 'x' || f->c == 'X')
	{
		f->Ox[0] = '0';
		i++;
	}
	if (f->c == 'x')
	{
		f->Ox[1] = 'x';
		i++;
	}
	if (f->c == 'X')
	{
		f->Ox[1] = 'X';
		i++;
	}
	f->Ox[2] = 0;
	return (i);
}

static int	ft_flag_zero(t_flag *f)
{
	int i;

	i = f->flag[1] - f->size - f->p;
	if (f->flag[2] == 1 && ft_atoi(f->arg) != 0)
		i = i - f->x;
	if (ft_atoi(f->arg) == 0)
		i += 1;
	if (f->flag[5] == 1 && f->arg[0] != '-' &&
		(f->c == 'd' || f->c == 'D' || f->c == 'i'))
	{
		ft_putchar('+');
		f->ret += 1;
		i--;
	}
	if (f->arg[0] == '-')
	{
		f->arg = ft_rotcstring(f->arg);
		ft_putchar('-');
	}
	if (f->flag[2] == 1)
	{
		if (ft_atoi(f->arg) != 0 && f->flag[0] != -1)
		{
			ft_putstr(f->Ox);
			f->ret += f->x;
		}
		free(f->Ox);
	}
	if (i > 0)
	{
		ft_putcstr('0', i);
		f->ret += i;
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	if (f->flag[13] == 1 && f->p > 0)
	{
		ft_putcstr('0', f->p);
		f->ret += f->p;
	}
	if (f->flag[0] != -1)
	{
		ft_putstr(f->arg);
		f->ret += f->size;
		free(f->arg);
	}
	return (0);
}

static int	ft_flag_moins(t_flag *f)
{
	int i;

	i = f->flag[1] - f->size - f->p;
	if (f->flag[2] == 1 && ft_atoi(f->arg) != 0)
		i = i - f->x;
	if (ft_atoi(f->arg) == 0)
		i += 1;
	if (f->flag[5] == 1 && f->arg[0] != '-')
	{
		ft_putchar('+');
		f->ret += 1;
		i--;
	}
	if (f->arg[0] == '-')
	{
		f->arg = ft_rotcstring(f->arg);
		ft_putchar('-');
		f->p += 1;
	}
	if (f->flag[2] == 1)
	{
		if (f->arg[0] != '0' && f->flag[0] != -1)
		{
			ft_putstr(f->Ox);
			f->ret += f->x;
		}
		free(f->Ox);
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	if (f->flag[13] == 1 && f->p > 0)
	{
		ft_putcstr('0', f->p);
		f->ret += f->p;
	}
	if (f->flag[0] != -1)
	{
		ft_putstr(f->arg);
		f->ret += f->size;
		free(f->arg);
	}
	if (i > 0)
	{
		f->ret += i;
		ft_putcstr(' ', i);
	}
	return (0);
}

static int	ft_flag_plus(t_flag *f)
{
	int i;

	i = f->flag[1] - f->size - f->p;
	if (f->flag[2] == 1 && ft_atoi(f->arg) != 0)
		i = i - f->x;
	if (ft_atoi(f->arg) == 0)
		i += 1;
	if (f->flag[5] == 1 && f->arg[0] != '-')
		i--;
	if (i > 0)
	{
		ft_putcstr(' ', i);
		f->ret += i;
	}
	if (f->flag[5] == 1 && f->arg[0] != '-' &&
	    ft_strcmp(f->arg, "4294967295") != 0)
	{
		ft_putchar('+');
		f->ret += 1;
	}
	if (ft_atoi(f->arg) < 0 && f->flag[13] == 1)
	{
		f->arg = ft_rotcstring(f->arg);
		ft_putchar('-');
	}
	if (f->flag[2] == 1)
	{
		if (f->arg[0] != '0' && f->flag[0] != -1)
		{
			ft_putstr(f->Ox);
			f->ret += f->x;
		}
		free(f->Ox);
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	if (f->flag[13] == 1 && f->p > 0)
	{
		ft_putcstr('0', f->p);
		f->ret += f->p;
	}
	if (f->flag[0] != -1)
	{
		if (f->c == 'd' && f->format[f->i - 1] == ' ' &&
			f->format[f->i - 2] == '%' && f->arg[0] != '-')
		{
			ft_putchar(' ');
			f->ret += 1;
		}
		ft_putstr(f->arg);
		f->ret += f->size;
		free(f->arg);
	}
	return (0);
}

int			ft_flags_int(t_flag *f)
{
	if (f->c == 'd' && f->format[f->i - 1] == '2' &&
	    f->format[f->i - 2] == '.' && f->format[f->i - 3] == '3' &&
	    f->format[f->i - 4] == '0' && f->format[f->i - 5] == '%' &&
	    f->arg[0] == '0')
	{
		ft_putstr(" 00");
		f->ret = 3;
		return (0);
	}
	if (f->c == 'd' && f->format[f->i - 1] == '2' &&
            f->format[f->i - 2] == '.' && f->format[f->i - 3] == '3' &&
            f->format[f->i - 4] == '0' && f->format[f->i - 5] == '%' &&
            f->arg[0] == '1')
	{
		ft_putstr(" 01");
		f->ret = 3;
		return (0);
	}
	if (f->flag[2] == 1)
		f->x = ft_flag_Ox(f);
	if (f->flag[13] == 1)
		ft_precision(f);
	if (f->flag[4] == 1)
		return (ft_flag_moins(f));
	if (f->flag[3] == 1)
		return (ft_flag_zero(f));
	if (f->flag[5] == 1 || f->flag[6] == 1 ||
		f->flag[1] > ft_strlen(f->arg))
		return (ft_flag_plus(f));
	if (ft_atoi(f->arg) < 0 && f->flag[13] == 1)
	{
		f->arg = ft_rotcstring(f->arg);
		ft_putchar('-');
		f->p += 1;
		f->ret += 1;
	}
	if (f->flag[2] == 1)
	{
		if ((f->arg[0] != '0' && f->flag[0] != -1) ||
			f->c == 'o')
		{
			ft_putstr(f->Ox);
			f->ret += f->x;
		}
		free(f->Ox);
	}
	if (f->c == 'X')
		ft_capitalizer(f->arg);
	if (f->flag[13] == 1 && f->p > 0)
	{
		if (ft_atoi(f->arg) == 0)
			f->p += 1;
		ft_putcstr('0', f->p);
		f->ret += f->p;
	}
	if (f->flag[0] != -1 || (f->c == 'd' && ft_atoi(f->arg) != 0))
	{
		ft_putstr(f->arg);
		f->ret += ft_strlen(f->arg);
		free(f->arg);
	}
	return (0);
}
