/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 02:34:49 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/08 15:27:06 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int *count)
{
	int	i;
	
	i = 0;
	if (!s)
		s = "(null)";
	while (s)
	{
		count++;
		ft_putchar(s);
		write(1, s[i], 1);
		i++;
	}
	return (count);
}
