/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:00:49 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:50:39 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n);

int	main(void)
{
	char *s = "Hello a world!";
	printf("%p\n", s + 6);
	printf("%p\n", ft_memchr(s, 97, 7));
	return (0);
}
*/
/*
int main(void)
{
	char data[] = { 'H', 'e', 'l', 'l', '\0', 'o', '!' };

	// memchr может искать дальше \0 — указываем длину
	printf("memchr: %p\n", data + 6);
	printf("memchr: %p\n", (void *)ft_memchr(data, '\0', 7));

	return 0;
}
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = s;
	while (n--)
	{
		if (*ptr == (unsigned char) c)
			return ((void *) ptr);
		ptr++;
	}
	return (NULL);
}
