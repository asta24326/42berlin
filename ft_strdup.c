/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 21:47:04 by asharafe          #+#    #+#             */
/*   Updated: 2025/07/13 22:26:49 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int	main(void)
{
	char	*src = "Hello world!";
	char	*dest;

	dest = ft_strdup(src);
	printf("Dest: %s\n", dest);
	free (dest);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

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
*/
// 
// char	*ft_strdup(const char *s)
// {
// 	size_t	s_len;
// 	char	*dest;
// 	size_t	i;

// 	i = 0;
// 	s_len = ft_strlen(s) + 1;
// 	dest = (char *)malloc(sizeof(char) * (s_len));
// 	if (dest == NULL)
// 		return (NULL);
// 	while (s_len > i)
// 	{
// 		dest[i] = s[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*dest;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (s_len + 1));
	if (dest == NULL)
		return (NULL);
	while (s_len > i)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
