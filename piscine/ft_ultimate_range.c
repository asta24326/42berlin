/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:12:03 by asharafe          #+#    #+#             */
/*   Updated: 2025/04/15 19:59:56 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
/*
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int	i;
	int	a;
	int	b;
	int	size;
	int	*arr;

	a = 5;
	b = 5;
	i = 0;
	size = ft_ultimate_range(&arr, a, b);
	while(i < size)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
*/

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size_of_range;

	size_of_range = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *) malloc((max - min) * sizeof(int));
	if (!(*range))
		return (-1);
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (size_of_range);
}
