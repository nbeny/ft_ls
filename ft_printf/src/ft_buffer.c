#include "../include/ft_printf.h"

int		ft_multibuf_ox(t_flag *f, t_list **begin_lst, size_t size)
{
	t_list	*lst;
	t_list	*new;
	size_t	i[2];

	i[0] = 0;
	lst = *begin_lst;
	while (lst->next)
		lst = lst->next;
	if (size > (4095 - lst->i))
	{
		i[1] = 4095 - lst->i;
		ft_strncpy(&lst->buf[lst->i], f->ox, i[1]);
		lst->i += i[1];
		i[0] += i[1];
		size -= i[1];
		while (size != 0)
		{
			if (size > 4095)
				i[1] = 4095;
			else
				i[1] = size;
			if (!(new = (t_list *)malloc(sizeof(t_list))))
				return (-1);
			lst->next = new;
			lst = lst->next;
			lst->i = 0;
			ft_strncpy(&lst->buf[lst->i], &f->ox[i[0]], i[1]);
			size -= i[1];
			i[0] += i[1];
			lst->i += i[1];
		}
		lst->next = NULL;
	}
	else
	{
		ft_strncpy(&lst->buf[lst->i], f->ox, size);
		lst->i += size;
	}
	return (0);
}

int		ft_multibuf_arg(t_flag *f, t_list **begin_lst, size_t size)
{
	t_list	*lst;
	t_list	*new;
	size_t	i[2];

	i[0] = 0;
	lst = *begin_lst;
	while (lst->next)
		lst = lst->next;
	if (size > (4095 - lst->i))
	{
		i[1] = 4095 - lst->i;
		ft_strncpy(&lst->buf[lst->i], f->arg, i[1]);
		lst->i += i[1];
		i[0] += i[1];
		size -= i[1];
		while (size != 0)
		{
			if (size > 4095)
				i[1] = 4095;
			else
				i[1] = size;
			if (!(new = (t_list *)malloc(sizeof(t_list))))
				return (-1);
			lst->next = new;
			lst = lst->next;
			lst->i = 0;
			ft_strncpy(&lst->buf[lst->i], &f->arg[i[0]], i[1]);
			size -= i[1];
			i[0] += i[1];
			lst->i += i[1];
		}
		lst->next = NULL;
	}
	else
	{
		ft_strncpy(&lst->buf[lst->i], f->arg, size);
		lst->i += size;
	}
	return (0);
}

int		ft_multibuf_nchar(t_list **begin_lst, int c, size_t size)
{
	t_list	*lst;
	t_list	*new;
	size_t	i;

	lst = *begin_lst;
	while (lst->next)
		lst = lst->next;
	if (size > (4095 - lst->i))
	{
		i = 4095 - lst->i;
		ft_cpynchar(&lst->buf[lst->i], c, i);
		lst->i += i;
		size -= i;
		while (size != 0)
		{
			if (size > 4095)
				i = 4095;
			else
				i = size;
			if (!(new = (t_list *)malloc(sizeof(t_list))))
				return (-1);
			lst->next = new;
			lst = lst->next;
			lst->i = 0;
			ft_cpynchar(&lst->buf[lst->i], c, i);
			lst->i += i;
			size -= i;
		}
		lst->next = NULL;
	}
	else
	{
		ft_cpynchar(&lst->buf[lst->i], c, size);
		lst->i += size;
	}
	return (0);
}

size_t		ft_booster(const char *format, size_t i, t_list **begin_lst)
{
	size_t	size;
	size_t	n;
	t_list	*lst;


	lst = *begin_lst;
	n = 0;
	while (format[i + n] != '\0' && format[i + n] != '%')
		n++;
	while (lst->next)
		lst = lst->next;
	if ((lst->i + n) < 4095)
	{
		ft_strncpy(&lst->buf[lst->i], (char *)&format[i], n);
		lst->i += n;
		i += n;
	}
	else
	{
		size = 4095 - lst->i;
		ft_strncpy(&lst->buf[lst->i], (char *)&format[i], size);
		lst->i += size;
		n -= size;
		while (n != 0)
		{
			if (n > 4095)
				size = 4095;
			else
				size = n;
			if (!(lst->next = (t_list *)malloc(sizeof(t_list))))
				return (-1);
			lst = lst->next;
			lst->i = 0;
			ft_strncpy(&lst->buf[lst->i], (char *)&format[i], size);
			lst->i += size;
			n -= size;
			i += size;
		}
		lst->next = NULL;
	}
	return (i);
}

char    *ft_cpynchar(char *dest, int c, size_t n)
{
	size_t i;

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
