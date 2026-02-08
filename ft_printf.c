/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 02:38:03 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/08 20:03:58 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

void handle_str_char(const char format, int *count, va_list args)
{
	if (format == 's')
	{
		ft_putstr(va_arg(args, int), count);
	}
	else if (format == 'c')
	{
		write(1, va_arg(args, int), 1);
	}
}

void handle_num(const char format, int *count, va_list args)
{
	if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (format == 'u')
		ft_print_u(va_arg(args, unsigned int), count);
}

void handle_hex(const char format, int *count, va_list args)
{
	if (format == 'p')
		ft_print_hex((unsigned long)va_arg(args, void *), count);
	else if (format == 'x')
		ft_lowercase_base(va_arg(args, unsigned int), count);
	else if (format == 'X')
		ft_uppercase_base(va_arg(args, unsigned int), count);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int i;
	int count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			handle_str_char(format[i], &count, args);
			handle_num(format[i], &count, args);
			handle_hex(format[i], &count, args);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}

int main(void)
{
	char s1[] = "someone in my mind ";
	char s2[] = "someone ";
	char s3[] = "not so different...";

	int val = 1337;

	ft_printf("%d \n %u \n %x \n %X", val, s1, s2, s3);
}
