/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:10:38 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/10/01 00:09:58 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Pseudocode
	Declare:
		index
		temp int to store value while swap
		length of array as args_len = (argc - 1)(minus name of programm)
		flag that smth swaped by deafult to 1(to start the loop)
		arr of int's
		
	Check if no or 1 argument passed -> show error
	
	Allocate array of ints with amount of (argc - 1)
	
	Loop while flag != 0
		set flag = 0
	
		Loop i = 1(from first arg) and until index != last index(arg_len)
			Start from the first arg(i = 1) and compare it to the next one(i + 1)
				if second is smaller
					swap numbers
					flag++
			i++
	
	print result
*/
#include "../lib_ft/libft.h"
#include <stdio.h>

long	*mem_alloc(int argc, char **argv);
long	*mem_alloc(int argc, char **argv);
void	ft_print(int argc, long *arr);

int	main(int argc, char **argv)
{
	int		i;
	int		flag;
	long	temp;
	long	*arr;

	arr = mem_alloc(argc, argv);
	flag = 1;
	while (flag != 0)
	{
		flag = 0;
		i = 0;
		while (i < (argc - 2))
		{
			if ((arr[i]) > arr[i + 1])
			{
				temp = (arr[i]);
				arr[i] = (arr[i + 1]);
				arr[i + 1] = temp;
				flag++;
			}
			i++;
		}
	}
	return (ft_print(argc, arr), free (arr), 0);
}

long	*mem_alloc(int argc, char **argv)
{
	int		i;
	long	*arr;

	i = 0;
	arr = malloc(sizeof(long) * (argc - 1));
	if (!arr)
		return (free(arr), NULL);
	while (i < (argc - 1))
	{
		arr[i] = atol(argv[i + 1]);
		if (arr[i] > INT_MAX && arr[i] < INT_MIN)
			free(arr);
		i++;
	}
	return (arr);
}

void	ft_print(int argc, long *arr)
{
	int	i;

	i = 0;
	while (i < (argc - 1))
	{
		ft_printf("index: %i, ", i);
		ft_printf("value: %i\n", (int)arr[i]);
		i++;
	}
}
