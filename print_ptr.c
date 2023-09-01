#include "ft_printf.h"

int	ptr_len(uintptr_t ptr)
{
	int	count;

	count = 0;
	while (ptr)
	{
		ptr = ptr / 16;
		count++;
	}
	return (count);
}

int	putptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		putptr(ptr/16);
		putptr(ptr%16);
	}
	else
		ft_putchar("0123456789abcdef"[ptr]);
	return (ptr_len(ptr));
}

int	put_ptr(uintptr_t ptr)
{
	int	printed_chars;

	printed_chars = 2;
	write(1, "0x", 2);
	if (ptr == 0)
	{
		write(1, "0", 1);
		printed_chars += 1;
	}
	else
		printed_chars += putptr(ptr);
	return (printed_chars);
}
