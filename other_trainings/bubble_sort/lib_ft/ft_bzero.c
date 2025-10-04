/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:47:43 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:53:20 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

void	ft_bzero(void *s, size_t n);

int	main(void)
{
	//for string
	int	i = 0;
	char	str[] = "Hello!";
	ft_bzero(str, 3);
	while(i < 5)
	{
		printf("str[%d] = '%c' (%d)\n", i, str[i], str[i]);
		i++;
	}

	//for array
	int	arr[5] = {1, 2, 3, 4, 5};
	ft_bzero(arr, sizeof(int) * 3);
	i = 0;
	while(i < 5)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		i++;
	}
	return (0);
}
//Fill memory with zeros (bytes containing '\0')
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = '\0';
}
