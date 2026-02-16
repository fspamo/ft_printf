/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 20:15:06 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/16 20:15:08 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr(int n, int *count);
int		ft_putchar(char c, int *count);
int		ft_putstr(char *s, int *count);
void	ft_print_hex(unsigned long val, int *count);
void	ft_print_u(unsigned int n, int *count);
void	ft_uppercase_base(unsigned long val, int *count);

#endif
