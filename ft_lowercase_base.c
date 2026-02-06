/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowercase_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:36:07 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/06 16:50:12 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

int	ft_lowercase_base(unsigned long	val, size_t count)
{
	char	*base;
	size_t	holder;

	base = "0123456789abcdef";
	if (count == (unsigned long) - 1)
		return (-1);
	if (val > 16)
		ft_lowercase_base(val / 16, count);
	holder = count;
	count += write(1, &base[val % 16], 1);
	if (count == holder - 1)
		return (-1);
	return (count);
}
