#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr(int n);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_print_hex(unsigned long val, size_t count);
int		ft_lowercase_base(unsigned long val, size_t count);
int		ft_uppercase(unsigned long val, size_t count);

#endif
