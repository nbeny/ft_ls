#include "libft.h"

void		ft_ushort_putnbr_base(unsigned short int nb, char *base)
{
	if (nb >= (unsigned short int)ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putnbr_base(nb % ft_strlen(base), base);
	}
	else
		ft_putchar(base[nb]);
}
