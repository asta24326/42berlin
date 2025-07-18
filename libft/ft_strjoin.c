/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 22:29:44 by asharafe          #+#    #+#             */
/*   Updated: 2025/07/13 22:15:52 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// 
// #include <stdio.h>

// size_t	ft_strlen(const char *s);
// // size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// char	*ft_strjoin(char const *s1, char const *s2);
// // size_t	ft_strlcat(char *dst, char *src, size_t size);

// int	main(void)
// {
// 	char	*s1 = "Hello, ";
// 	char	*s2 = "world!";

// 	char	*result = ft_strjoin(s1, s2);
// 	printf("Result: %s\n", result);
// 	free (result);
// 	return (0);
// }

// size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (*s++)
// 		i++;
// 	return (i);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	src_len;

// 	i = 0;
// 	src_len = ft_strlen(src);
// 	if (size > 0)
// 	{
// 		while (i < (size - 1) && src[i])
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	return (src_len);
// }

// size_t	ft_strlcat(char *dst, char *src, size_t size)
// {
// 	unsigned int	src_len;
// 	unsigned int	dest_len;
// 	unsigned int	i;

// 	src_len = ft_strlen(src);
// 	dest_len = ft_strlen(dst);
// 	i = 0;
// 	if (dest_len >= size)
// 	{
// 		return (size + src_len);
// 	}
// 	while (((dest_len + i) < (size - 1)) && src[i])
// 	{
// 		dst[dest_len + i] = src[i];
// 		i++;
// 	}
// 	dst[dest_len + i] = '\0';
// 	return (dest_len + src_len);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final_str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	final_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!final_str)
		return (NULL);
	i = 0;
	while (s1 && (len_s1 > i))
	{
		final_str[i] = s1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		final_str[i] = s2[i - len_s1];
		i++;
	}
	final_str[i] = '\0';
	return (final_str);
}
