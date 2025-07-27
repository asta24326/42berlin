/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:38:11 by asharafe          #+#    #+#             */
/*   Updated: 2025/04/15 19:09:11 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
/*
#include <stdio.h>

int	*ft_range(int min, int max);


int	main(void)
{
	int	i;
	int	a;
	int	b;
	int	*arr;

	a = 1;
	b = 5;
	i = 0;
	arr = ft_range(a, b);
	while(i < b - a)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
*/

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	arr = (int *) malloc((max - min) * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
