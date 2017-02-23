#include "libft.h"

void		ft_size_putnbr_base(size_t nb, char *base)
{
	if (nb >= (size_t)ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putnbr_base(nb % ft_strlen(base), base);
	}
	else
		ft_putchar(base[nb]);
}
