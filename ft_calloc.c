/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 21:20:57 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:47:49 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

int	main(void)
{
	int	*arr = (int *)ft_calloc(5, sizeof(int));

	if (arr == NULL)
	{
		printf("Error memory allocation!\n");
		return (1);
	}

	size_t	i = 0;
	while (i < 5)
	{
		printf("Value: %d\n", arr[i]);
		i++;
	}

	free (arr);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = '\0';
}
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (int *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
