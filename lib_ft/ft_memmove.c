/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:47:43 by asharafe          #+#    #+#             */
/*   Updated: 2025/07/13 22:00:49 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// void	*ft_memmove(void *dest, const void *src, size_t n);

// int	main(void)
// {
// 	//for string
// 	char	src[6] = "abcde";
// 	ft_memmove(src + 2, src + 3, 3);
// 	printf("String: %s\n", src);
// 	//for array
// 	int	i = 0;
// 	int	arr[5] = {1, 2, 3, 4, 5};
// 	ft_memset(arr, 0, sizeof(int) * 3);
// 	while(i < 5)
// 	{
// 		printf("arr[%d] = %d\n", i, arr[i]);
// 		i++;
// 	}
// 	return (0);
// }
// //Copies memory from source to destination

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			((unsigned char *)dest)[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	return (dest);
}
