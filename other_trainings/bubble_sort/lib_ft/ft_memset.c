/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:47:43 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:50:54 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n);

int	main(void)
{
	//for string
	char	str[] = "Hello!";
	ft_memset(str, 'A', 3);
	printf("String: %s\n", str);

	//for array
	int	i = 0;
	int	arr[5] = {1, 2, 3, 4, 5};
	ft_memset(arr, 0, sizeof(int) * 3);
	while(i < 5)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		i++;
	}
	return (0);
}
//Fill memory with with a value int c
*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = (unsigned char) c;
	return (s);
}
