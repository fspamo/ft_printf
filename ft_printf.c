/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 02:38:03 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/05 03:12:58 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list args;
	int i;
	int count;
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
	ft_printf("%s\n %c", "merhaba", 'c');
}
