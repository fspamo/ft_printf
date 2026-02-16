/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 20:17:47 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/16 20:17:48 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr(int n, int *count)
{
	long int	nb;
	char		c;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		(*count)++;
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, count);
	c = (nb % 10) + '0';
	if (write(1, &c, 1) == -1)
	{
		*count = -1;
		return (-1);
	}
	(*count)++;
	return (*count);
}
