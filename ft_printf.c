/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 02:38:03 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/07 00:56:19 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int *handle_num(const char *format, int i, int *count, va_list args)
{
	if (format[i] == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (format[i] == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (format[i] == 'p')
	{
		count += write(1, "0x", 2);
		ft_print_hex(va_arg(args, unsigned long), count, format[i]);
	}
	else if (format[i] == 'd' || format[i] == 'i')
		ft_putnbr(va_arg(args, int), count);

	return (count);
}

int *handle_hex(char *format, int i, int *count)
{
	if (format[i] == 'p')
		count += ft_print_hex(va_arg(args, int), count);
	else if (format[i] == 'x')
		count += ft_lowercase_base(va_arg(args, int), count);
	else if (format[i] == 'X')
		count += ft_uppercase_base(va_arg(args, int), count);
	return (count);
}

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
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
				handle_num(format, i, &count);
			if (format[i] == 'x' || format[i] == 'X' || format[i] == 'p')
				handle_hex(format, i, &count);
		}
		else
			count += ft_putchar(format[i]);
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

	ft_printf("%s\n%s\n%s\n%d\n%p", s1, s2, s3, val, val);
}
