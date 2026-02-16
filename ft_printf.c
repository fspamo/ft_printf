/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 23:23:51 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/14 04:58:29 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	handle_str_char(const char format, int *count, va_list args)
{
	char	c;

	if (format == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (format == 'c')
	{
		c = (char)va_arg(args, int);
		if (write(1, &c, 1) == -1)
			return (-1);
		(*count)++;
	}
	return (0);
}

static void	handle_num(const char format, int *count, va_list args)
{
	if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (format == 'u')
		ft_print_u(va_arg(args, unsigned int), count);
}

static int	handle_hex(const char format, int *count, va_list args)
{
	void	*p_nilcase;

	if (format == 'p')
	{
		p_nilcase = va_arg(args, void *);
		if (p_nilcase == NULL)
			ft_putstr("(nil)", count);
		else
		{
			if (write(1, "0x", 2) != 2)
				return (-1);
			*count += 2;
			ft_print_hex((unsigned long)p_nilcase, count);
		}
	}
	else if (format == 'x')
		ft_print_hex(va_arg(args, unsigned int), count);
	else if (format == 'X')
		ft_uppercase_base(va_arg(args, unsigned int), count);
	return (0);
}

static int	handle_flag(const char *format, int *i, int *count, va_list args)
{
	if (format[*i] == '%')
	{
		(*i)++;
		if (format[*i] == '\0')
			return (-1);
		if (format[*i] == '%')
			ft_putchar('%', count);
		else if (format[*i] == 's' || format[*i] == 'c')
			handle_str_char(format[*i], count, args);
		else if (format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'u')
			handle_num(format[*i], count, args);
		else if (format[*i] == 'p' || format[*i] == 'x' || format[*i] == 'X')
			handle_hex(format[*i], count, args);
		else
			return (-1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	if (!format)
		return (va_end(args), -1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (handle_flag(format, &i, &count, args) == -1)
				return (-1);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	return (va_end(args), count);
}
