#include "../include/ft_printf.h"

int		ft_handler_q(t_flag *f, va_list *ap)
{
	f->arg = ft_uitoa_base((unsigned int)va_arg(*ap, unsigned int), 5);
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
