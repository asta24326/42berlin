/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:53:10 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:52:06 by asharafe         ###   ########.fr       */
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
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (i < (size - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
