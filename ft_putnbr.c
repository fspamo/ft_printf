/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 01:38:08 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/08 18:49:10 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	get_digit(int n)
{
	int	digit;
	
	digit = 0;
	if (n <= 0)
		digit++;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

int	ft_putnbr(int n, int *count)
{
	long int	nb;
	char		c;
	int			original_n;

	original_n = n;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, count);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	if (count && nb == (long)original_n)
		*count += get_digit(original_n);
	
	return (*count);
}
