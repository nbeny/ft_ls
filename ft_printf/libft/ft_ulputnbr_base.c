#include "libft.h"

void		ft_ulputnbr_base(unsigned long int nb, char *base)
{
	if (nb >= (unsigned long int)ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putnbr_base(nb % ft_strlen(base), base);
	}
	else
		ft_putchar(base[nb]);
}
