/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowercase_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:36:07 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/09 01:44:59 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

int	ft_lowercase_base(unsigned long val, size_t *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (val >= 16)
		if (ft_lowercase_base(val / 16, count) == -1)
			return (-1);
	if (write(1, &base[val % 16], 1) == -1)
		return (-1);
	(*count)++;
	return (0);
}
