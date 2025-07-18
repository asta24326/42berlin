/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:52:37 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:52:37 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int	main(void)
{
	char str[] = "   	Hello, World!		 		";
	char	*set = "\t\n ";
	char	*trimmed_str;

	trimmed_str = ft_strtrim(str, set);
	printf("Original: '%s'\n", str);
	printf("Trimmed: '%s'\n", trimmed_str);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char) c)
		s++;
	if (*s == (unsigned char) c || !c)
		return ((char *) s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	real_len;

	if (!s)
		return (NULL);
	real_len = ft_strlen(s);
	if (start >= real_len)
		return (ft_strdup(""));
	if (len > real_len - start)
		len = real_len - start;
	ptr = (char *)malloc(sizeof(char) * len +1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s[start], len +1);
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s) + 1;
	ptr = (char *)malloc(sizeof(char) * len);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, len);
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i_start;
	size_t	i_end;
	char	*trim_str;

	if (!s1 || !set)
		return (NULL);
	i_start = 0;
	i_end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i_start]))
	{
		if (!s1[i_start])
			break ;
		i_start++;
	}
	if (i_start == i_end + 1)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[i_end]))
		i_end--;
	trim_str = ft_substr(s1, i_start, i_end - i_start + 1);
	if (!trim_str)
		return (NULL);
	return (trim_str);
}
