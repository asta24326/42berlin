/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:02:09 by asharafe          #+#    #+#             */
/*   Updated: 2025/04/14 11:49:58 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>

int	ft_is_prime(int nb);

int	main(void)
{
	printf("%d\n", ft_is_prime(17));
}

*/
int	ft_is_prime(int nb)
{
	int	i;

	i = 0;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
