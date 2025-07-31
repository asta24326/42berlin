/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:10:22 by asharafe          #+#    #+#             */
/*   Updated: 2025/08/01 00:35:41 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int	ft_atoi(char *str);

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("No input argument");
		return (1);
	}
	printf("final int:%d", ft_atoi(argv[1]));
	return (0);
}
*/

int	ft_atoi(const char *nptr)
{
	int		i;
	long	result;
	int		sign;
	int		digit;

	digit = 0;
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
	return ((int)(result * sign));
}
