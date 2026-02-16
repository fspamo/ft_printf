/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 20:16:14 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/16 20:16:15 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c, int *count)
{
	if (write(1, &c, 1) == -1)
	{
		*count = -1;
		return (-1);
	}
	(*count)++;
	return (*count);
}
