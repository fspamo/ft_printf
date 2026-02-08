/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:30:10 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/08 17:03:01 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex(unsigned long val, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (val >= 16)
		ft_print_hex(val / 16, count);
	if (write(1, &base[val % 16], 1) == -1)
	{
		*count = -1;
		return;
	}
	if (*count != -1)
		(*count)++;
}
