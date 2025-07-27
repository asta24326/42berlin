/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:30:39 by asharafe          #+#    #+#             */
/*   Updated: 2025/04/14 12:16:36 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>
int	ft_recursive_factorial(int nb);

int	main(void)
{
	int	nb;

	nb = 3;
	printf("Number: %d, factorial: %d\n", nb, (ft_recursive_factorial(nb)));
	return (0);
}


int	ft_recursive_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	result = nb * ft_recursive_factorial(nb - 1);
	return (result);
}
