/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:17:11 by asharafe          #+#    #+#             */
/*   Updated: 2025/07/14 16:57:03 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final_str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	final_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!final_str)
		return (NULL);
	i = 0;
	while (len_s1 > i)
	{
		final_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
	{
		final_str[i + j] = s2[j];
		j++;
	}
	final_str[i + j] = '\0';
	return (final_str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	if ((char) c == '\0')
		return ((char *)s);
	return (NULL);
}
