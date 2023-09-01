#include "ft_printf.h"

int nb_len(int nb)
{
	int	c;

	c = 0;
	if (nb < 0)
	{
		nb = -nb;
		c++;
	}
	while (nb)
	{
		nb = nb / 10;
		c++;
	}
	return (c);
}

int	ft_putnbr(int nb)
{
	int c;

	c = nb_len(nb);
	if (nb == 0)
	{
		write(1, "0", 1);	
		return (1);
	}
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else
		ft_putchar(nb + '0');
	return (c);
}

int nb_lenu(unsigned int nb)
{
	int	c;

	c = 0;
	while (nb)
	{
		nb = nb / 10;
		c++;
	}
	return (c);
}

int	ft_putnbru(unsigned int nb)
{
	int c;

	c = nb_lenu(nb);
	if (nb == 0)
	{
		write(1, "0", 1);	
		return (1);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else
		ft_putchar(nb + '0');
	return (c);
}