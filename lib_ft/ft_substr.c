/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 22:29:44 by asharafe          #+#    #+#             */
/*   Updated: 2025/07/14 16:38:01 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//
// #include <stdio.h>
// size_t	ft_strlen(const char *s);
// char	*ft_strdup(const char *s);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
//
// int	main(void)
// {
// 	char	*src = "Hello, world";
// 	char	*dest;
//
// 	dest = ft_substr(src, 5, 3);
// 	printf("Src: %s\n", src);
// 	printf("Dest: %s\n", dest);
// 	free (dest);
// 	return (0);
// }
//
// size_t	ft_strlen(const char *s)
// {
// 	int	i;
//
// 	i = 0;
// 	while (*s++)
// 		i++;
// 	return (i);
// }
//
// char	*ft_strdup(const char *s)
// {
// 	size_t	s_len;
// 	char	*dest;
// 	size_t	i;
//
// 	i = 0;
// 	s_len = ft_strlen(s);
// 	dest = (char *)malloc(sizeof(char) * (s_len + 1));
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
//
//
// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*ptr;
// 	size_t	s_len;
//
// 	if (!s)
// 		return (NULL);
// 	s_len = ft_strlen(s);
// 	if (start >= s_len)
// 		return (ft_strdup(""));
// 	if (len > s_len - start)
// 		len = s_len - start;
// 	ptr = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!ptr)
// 		return (NULL);
// 	ft_strlcpy(ptr, &s[start], len + 1);
// 	return (ptr);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	str_len;
	size_t	i;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (len > i)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
