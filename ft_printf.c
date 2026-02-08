/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 02:38:03 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/09 01:26:42 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

void handle_str_char(const char format, int *count, va_list args)
{
    char c;
    
    if (format == 's')
    {
        ft_putstr(va_arg(args, char *), count);
    }
    else if (format == 'c')
    {
        c = (char)va_arg(args, int);
        write(1, &c, 1);
        (*count)++;
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
    {
        write(1, "0x", 2);
        *count += 2;
        ft_print_hex((unsigned long)va_arg(args, void *), count);
    }
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
            if (format[i] == '%')
                ft_putchar('%', &count);
            else if (format[i] == 's' || format[i] == 'c')
                handle_str_char(format[i], &count, args);
            else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
                handle_num(format[i], &count, args);
            else if (format[i] == 'p' || format[i] == 'x' || format[i] == 'X')
                handle_hex(format[i], &count, args);
        }
        else
            ft_putchar(format[i], &count);
        i++;
    }
    va_end(args);
    return (count);
}

#include <stdio.h>
#include <limits.h>

int main(void)
{
    int ft_ret;
    int std_ret;

    printf("=== CHARACTER TESTS ===\n");
    ft_ret = ft_printf("ft:  [%c]\n", 'A');
    std_ret = printf("std: [%c]\n", 'A');
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  [%c%c%c]\n", 'a', 'b', 'c');
    std_ret = printf("std: [%c%c%c]\n", 'a', 'b', 'c');
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  [%c]\n", 0);
    std_ret = printf("std: [%c]\n", 0);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    printf("=== STRING TESTS ===\n");
    ft_ret = ft_printf("ft:  [%s]\n", "Hello World");
    std_ret = printf("std: [%s]\n", "Hello World");
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  [%s]\n", "");
    std_ret = printf("std: [%s]\n", "");
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    printf("=== INTEGER TESTS ===\n");
    ft_ret = ft_printf("ft:  [%d]\n", 42);
    std_ret = printf("std: [%d]\n", 42);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  [%d]\n", -42);
    std_ret = printf("std: [%d]\n", -42);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  [%d]\n", 0);
    std_ret = printf("std: [%d]\n", 0);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  [%i]\n", INT_MAX);
    std_ret = printf("std: [%i]\n", INT_MAX);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  [%i]\n", INT_MIN);
    std_ret = printf("std: [%i]\n", INT_MIN);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    printf("=== UNSIGNED TESTS ===\n");
    ft_ret = ft_printf("ft:  [%u]\n", 42);
    std_ret = printf("std: [%u]\n", 42);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  [%u]\n", 0);
    std_ret = printf("std: [%u]\n", 0);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  [%u]\n", UINT_MAX);
    std_ret = printf("std: [%u]\n", UINT_MAX);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  [%u]\n", -42);
    std_ret = printf("std: [%u]\n", -42);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    printf("=== HEXADECIMAL LOWERCASE TESTS ===\n");
    ft_ret = ft_printf("ft:  [%x]\n", 255);
    std_ret = printf("std: [%x]\n", 255);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  [%x]\n", 0);
    std_ret = printf("std: [%x]\n", 0);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  [%x]\n", -1);
    std_ret = printf("std: [%x]\n", -1);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    printf("=== HEXADECIMAL UPPERCASE TESTS ===\n");
    ft_ret = ft_printf("ft:  [%X]\n", 255);
    std_ret = printf("std: [%X]\n", 255);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  [%X]\n", 0);
    std_ret = printf("std: [%X]\n", 0);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    printf("=== POINTER TESTS ===\n");
    int x = 42;
    ft_ret = ft_printf("ft:  [%p]\n", &x);
    std_ret = printf("std: [%p]\n", &x);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  [%p]\n", NULL);
    std_ret = printf("std: [%p]\n", NULL);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    printf("=== PERCENT TESTS ===\n");
    ft_ret = ft_printf("ft:  [%%]\n");
    std_ret = printf("std: [%%]\n");
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  [%%%%]\n");
    std_ret = printf("std: [%%%%]\n");
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    printf("=== MIXED TESTS ===\n");
    ft_ret = ft_printf("ft:  [%s %d %c %x]\n", "test", 42, 'A', 255);
    std_ret = printf("std: [%s %d %c %x]\n", "test", 42, 'A', 255);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  [%c%c%c%c%c]\n", 'H', 'e', 'l', 'l', 'o');
    std_ret = printf("std: [%c%c%c%c%c]\n", 'H', 'e', 'l', 'l', 'o');
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  No format\n");
    std_ret = printf("std: No format\n");
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf("ft:  [%d %i %u]\n", -123, 456, 789);
    std_ret = printf("std: [%d %i %u]\n", -123, 456, 789);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);

    return (0);
}
