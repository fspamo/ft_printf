/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 01:38:08 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/05 17:18:12 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_digit(int n)
{
	int	digit;

	digit = 1;
	if (n < 0)
	{
		digit++;
	}
	while (n >= 10)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

int	ft_putnbr(int n)
{
	long int	nb;
	char		c;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	c = (nb % 10) + '0';
	write(1, &c, 1);
	return (get_digit(nb));
}
