#include "libft.h"

void		ft_umax_putnbr_base(uintmax_t nb, char *base)
{
	if (nb >= (uintmax_t)ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putnbr_base(nb % ft_strlen(base), base);
	}
	else
		ft_putchar(base[nb]);
}
