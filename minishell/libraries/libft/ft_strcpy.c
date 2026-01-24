/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:53:10 by asharafe          #+#    #+#             */
/*   Updated: 2025/10/26 17:50:49 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int	main(void)
{
	char			*src;
	char			dest[11];
	unsigned int	size;
	unsigned int	src_length;

	size = 11;
	src = "0123456789";
	src_length = ft_strlcpy(dest, src, size);
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);
	printf("Lenght of src: %u\n", src_length);
	if (src_length >= size)
	{
		printf("Warning: String src is truncated, dest copied not fully!\n");
	}
	if (src_length < size)
	{
		printf("Strings copied successfully!\n");
	}
	return (0);
}
*/
char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
