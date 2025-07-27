/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:16:40 by asharafe          #+#    #+#             */
/*   Updated: 2025/04/14 12:11:38 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>

int	ft_find_next_prime(int nb);

int	main(void)
{
	printf("%d\n", ft_find_next_prime(8));
}
*/

int	ft_find_next_prime(int nb)
{
	int	i;
	int	prime_flag;

	if (nb == 2)
		return (2);
	while (nb >= 0)
	{
		if (nb > 1)
		{
			prime_flag = 1;
			i = 2;
			while (i * i <= nb && prime_flag)
			{
				if (nb % i == 0)
					prime_flag = 0;
				else
					i++;
			}
			if (prime_flag)
				return (nb);
		}
		nb++;
	}
	return (1);
}
