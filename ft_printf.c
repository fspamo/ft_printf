/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 02:38:03 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/06 16:09:13 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list args;
	int		i;
	int		count;
	va_start(args, format);

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			count += ft_putchar(va_arg(args, int));
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			count += ft_putstr(va_arg(args, char *));
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'd')
		{
			count += ft_putnbr(va_arg(args, int));
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'p')
		{
			write (1, "0x", 2);
			count += ft_print_hex(va_arg(args, unsigned long), count);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'x')
		{
			write (1, "0x", 2);
			count += ft_lowercase_base(va_arg(args, unsigned long), count);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'X')
		{
			write (1, "0x", 2);
			count += ft_uppercase_base(va_arg(args, unsigned long), count);
			i++;
		}
		else
		{
			count += ft_putchar(format[i]);
		}
		i++;
	}

	va_end(args);
	return (count);
}

int main(void)
{
	int nbr = 9;
	int nb = 13;
	ft_printf("%p, %p", nbr, nb);
}

