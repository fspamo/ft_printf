/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 02:34:49 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/05 03:11:22 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int count)
{

	if (!s)
		s = "(null)";
	while (s)
	{
		count++;
		ft_putchar(s);
		i++;
	}
	return (count);
}
