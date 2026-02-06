/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:30:10 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/06 14:44:16 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stddef.h>

int	ft_print_hex(unsigned long	val, size_t count)
{
	char	*base;
	size_t	holder;

	base = "0123456789abcdef";
	// count = write(1, "0x", 2);
	if (count == (unsigned long)-1)
		return (-1);
	if (val > 16)
		ft_print_hex(val / 16, count);
	holder = count;
	count += write(1, &base[val % 16], 1);
	if (count == holder - 1)
		return (-1);
	return (count);
}
