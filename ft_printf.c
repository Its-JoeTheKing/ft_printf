#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list args;
	int	i;
	int	printed_chars;

	va_start(args, format);
	i = 0;
	printed_chars = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i+1] == 's')
				printed_chars += ft_putstr(va_arg(args, char *));
			else if (format[i+1] == 'c')
				printed_chars += ft_putchar((char)va_arg(args, int));
			else if (format[i+1] == 'd' || format[i+1] == 'i')
				printed_chars += ft_putnbr(va_arg(args, int));
			else if (format[i+1] == 'u')
				printed_chars += ft_putnbru(va_arg(args, unsigned int));
			else if (format[i+1] == 'p')
				printed_chars += put_ptr(va_arg(args, uintptr_t));
			else if (format[i+1] == 'x')
				printed_chars += put_hex(va_arg(args, unsigned int), 0);
			else if (format[i+1] == 'X')
				printed_chars += put_hex(va_arg(args, unsigned int), 1);
			else if (format[i+1] == '%')
				printed_chars += ft_putchar('%');
			i++;
		}
		else
			printed_chars += ft_putchar(format[i]);
		i++;
	}
	return (printed_chars);
}
