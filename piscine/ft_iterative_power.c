/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:44:11 by asharafe          #+#    #+#             */
/*   Updated: 2025/04/13 15:56:50 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <stdio.h>
int	ft_iterative_power(int nb, int power);

int	main(void)
{
	int	nb;
	int	power;

	nb = 2;
	power = 5;
	printf("Number: %d, result: %d\n", nb, (ft_iterative_power(nb, power)));
	return (0);
}
*/

int	ft_iterative_power(int nb, int power)
{
	int	result;
	int	i;

	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	i = 0;
	result = 1;
	while (power > i)
	{
		result = result * nb;
		i++;
	}
	return (result);
}
