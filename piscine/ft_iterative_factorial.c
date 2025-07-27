/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:16:47 by asharafe          #+#    #+#             */
/*   Updated: 2025/04/13 15:43:41 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <stdio.h>

int	ft_iterative_factorial(int nb);

int	main(void)
{
	int	nb;

	nb = 3;
	printf("Number: %d, factorial: %d\n", nb, (ft_iterative_factorial(nb)));
	return (0);
}
*/

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	while (nb > 1)
	{
		result = result * nb;
		nb--;
	}
	return (result);
}
