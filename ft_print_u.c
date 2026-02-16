/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 20:15:56 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/16 20:15:57 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_u(unsigned int n, int *count)
{
	char	c;

	if (n >= 10)
		ft_print_u(n / 10, count);
	c = (n % 10) + '0';
	if (write(1, &c, 1) == -1)
		*count = -1;
	else if (*count != -1)
		(*count)++;
}
