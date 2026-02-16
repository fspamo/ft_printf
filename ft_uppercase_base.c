/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uppercase_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:07:16 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/06 16:49:54 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_uppercase_base(unsigned long val, int *count)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (val >= 16)
		ft_uppercase_base(val / 16, count);
	if (write(1, &base[val % 16], 1) == -1)
	{
		*count = -1;
		return ;
	}
	if (*count != -1)
		(*count)++;
}
