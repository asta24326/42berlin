/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:41:50 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:50:45 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	main(void)
{
	
	int				result;
	unsigned int	n;

	int	src[] = {1, 2, 3, 4, 5, 6, 7};
	int	dest[] = {1, 2, 3, 4, 0, 5, 6, 7};
	n = 5 * sizeof(int);
	result = ft_memcmp(src, dest, n);
	if (result == 0)
		printf("Strings are equal!\n");
	if (result > 0)
		printf("Src is greater that dest!\n");
	if (result < 0)
		printf("Dest is greater that src!\n");
	return (0);
}
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}
