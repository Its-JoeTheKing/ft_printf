#include "ft_printf.h"

int	hex_len(unsigned int hex)
{
	int	count;

	count = 0;
	while (hex)
	{
		hex = hex / 16;
		count++;
	}
	return (count);
}

int	puthex(unsigned int hex, char *base)
{
	if (hex >= 16)
	{
		puthex(hex / 16, base);
		puthex(hex % 16, base);
	}
	else
		ft_putchar(base[hex]);
	return (hex_len(hex));
}

int	put_hex(unsigned int hex, int CAP)
{
	if (hex == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (CAP)
		return (puthex(hex, "0123456789ABCDEF"));
	else
		return (puthex(hex, "0123456789abcdef"));
}
