/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 20:17:59 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/16 20:18:01 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(char *s, int *count)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		if (write(1, &s[i], 1) == -1)
		{
			*count = -1;
			return (-1);
		}
		i++;
		*count = *count + 1;
	}
	return (*count);
}
