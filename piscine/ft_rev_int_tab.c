/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 19:28:17 by asharafe          #+#    #+#             */
/*   Updated: 2025/03/30 19:28:24 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int	arr[5];
	int	size;
	int	printcount;

	printcount = 0;
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	size = 5;
	while (printcount < size)
	{
		printf("%d", arr[printcount]);
		printcount++;
	}
	printf("\n");
	printcount = 0;
	ft_rev_int_tab(arr, size);
	while (printcount < size)
	{
		printf("%d", arr[printcount]);
		printcount++;
	}
	printf("\n");
	return (0);
}
*/

void	ft_rev_int_tab(int *tab, int size)
{
	int	last;
	int	temp;
	int	first;

	if (size <= 1)
	{
		return ;
	}
	last = size - 1;
	first = 0;
	while (first < last)
	{
		temp = tab[first];
		tab[first] = tab[last];
		tab[last] = temp;
		first++;
		last--;
	}
}
