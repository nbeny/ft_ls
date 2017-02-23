#include "libft.h"

void		ft_uchar_putnbr_base(unsigned char nb, char *base)
{
	if (nb >= (unsigned char)ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putnbr_base(nb % ft_strlen(base), base);
	}
	else
		ft_putchar(base[nb]);
}
