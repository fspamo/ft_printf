#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr(int n, int *count);
int		ft_putchar(char c, int *count);
int		ft_putstr(char *s, int *count);
int		ft_print_hex(unsigned long val, int *count);
int		ft_lowercase_base(unsigned long val, int *count);
int		ft_uppercase_base(unsigned long val, int *count);
int		ft_print_u(unsigned int n, int *count);

#endif
