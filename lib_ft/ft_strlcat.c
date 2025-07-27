/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:32:28 by asharafe          #+#    #+#             */
/*   Updated: 2025/07/25 18:57:26 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void			ft_fill_array(char *src, char *dest);
size_t	ft_strlen(const char *s);

int	main(void)
{
	char			dest[10];
	unsigned int	full_size_of_dest;
	char			*src;

	full_size_of_dest = 10;
	src = "12345678";
	ft_fill_array("1234", dest);
	printf("Initial dest: %s\n", dest);
	if (ft_strlcat(dest, src, full_size_of_dest) >= full_size_of_dest)
		printf("Buffer is less, string truncated\n");
	else
		printf("String copied fully\n");
	printf("Result dest: %s\n", dest);
	return (0);
}

void	ft_fill_array(char *input, char *dest)
{
	while (*input)
	{
		*dest = *input;
		input++;
		dest++;
	}
	while (*dest)
	{
		*dest = '\0';
		dest++;
	}
	*dest = '\0';
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	i = 0;
	if (dest_len >= size)
	{
		return (size + src_len);
	}
	while (((dest_len + i) < (size - 1)) && src[i])
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
