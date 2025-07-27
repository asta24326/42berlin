/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 19:28:44 by asharafe          #+#    #+#             */
/*   Updated: 2025/03/30 19:28:50 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int arr[5];
	int size;
	int printcounter;

	arr[0] = 3;
	arr[1] = 4;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 5;
	size = 5;
	printcounter = 0;
	
	while (printcounter < size)
	{
		printf("%d", arr[printcounter]);
		printcounter++;
	}
	printf("\n");
	
	ft_sort_int_tab(arr, size);

	printcounter = 0;
	while (printcounter < size)
	{
		printf("%d", arr[printcounter]);
		printcounter++;
	}
	printf("\n");
	
	return (0);
}
*/

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;
	int	swapcount;

	if (size <= 1)
	{
		return ;
	}
	swapcount = 1;
	while (swapcount > 0)
	{
		swapcount = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				swapcount++;
			}
			i++;
		}
	}
}
