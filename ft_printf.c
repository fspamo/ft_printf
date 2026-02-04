/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 02:38:03 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/05 02:16:30 by cbozkurt         ###   ########.fr       */
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
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'c')
			ft_putchar(va_arg(args, int));
		else if (format[i] == '%' && format[i + 1] == 's')
			ft_putstr(va_arg(args, int));
		i++;
	}

	va_end(args);
	return (count);
}

int main(void)
{
	ft_printf("%c", 'a');
}
