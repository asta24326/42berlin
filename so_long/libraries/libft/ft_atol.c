/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 22:22:25 by asharafe          #+#    #+#             */
/*   Updated: 2025/09/20 21:26:12 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	i = 0;
	result = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || (nptr[i] == ' '))
		i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return ((result * sign));
}
