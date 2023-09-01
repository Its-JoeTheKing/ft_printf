#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

int     ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int nb_len(int nb);
int nb_lenu(unsigned int nb);
int	ft_putnbru(unsigned int nb);
int	ptr_len(uintptr_t ptr);
int	putptr(uintptr_t ptr);
int	put_ptr(uintptr_t ptr);
int	hex_len(unsigned int hex);
int	puthex(unsigned int hex, char *base);
int	put_hex(unsigned int hex, int CAP);

#endif
