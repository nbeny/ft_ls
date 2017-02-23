#include "libft.h"

void		ft_uputnbr_base(unsigned int nb, char *base)
{
	if (nb >= (unsigned int)ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putnbr_base(nb % ft_strlen(base), base);
	}
	else
		ft_putchar(base[nb]);
}
