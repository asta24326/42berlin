/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:57:37 by asharafe          #+#    #+#             */
/*   Updated: 2025/04/13 16:05:24 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <stdio.h>
int	ft_recursive_power(int nb, int power);

int	main(void)
{
	int	nb;
	int	power;

	nb = 5;
	power = 0;
	printf("Number: %d, result: %d\n", nb, (ft_recursive_power(nb, power)));
	return (0);
}
*/

int	ft_recursive_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = nb * ft_recursive_power(nb, power - 1);
	return (result);
}
