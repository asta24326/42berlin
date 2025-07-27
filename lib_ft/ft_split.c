/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:51:19 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 13:00:49 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);
size_t	ft_count_words(const char *s, char c);
size_t	ft_strlen(const char *s);
char **ft_clean_all(char **arr, size_t word_index);

int	main(void)
{
	char	str[] = "Hello, Wo rld!    Love Yo u!";
	char	c = ' ';
	char	**new_arr;
	size_t	i;

	i = 0;
	new_arr = ft_split(str, c);
	if (!new_arr)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	printf("Original: %s\n", str);
	while (new_arr[i] != NULL)
		printf("%s\n", new_arr[i++]);
	i = 0;
	while (new_arr[i] != NULL)
		free (new_arr[i++]);
	free (new_arr);
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
size_t	custom_count_words(const char *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if ((s[i] != c) && (i == 0 || s[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

char	**custom_clean_all(char **arr, size_t word_index)
{
	while (word_index > 0)
	{
		word_index--;
		free(arr[word_index]);
	}
	free(arr);
	return (NULL);
}

char	**custom_split_arr_fill(char **new_arr, const char *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	word_len;
	size_t	word_index;

	i = 0;
	word_index = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		word_len = i - start;
		new_arr[word_index] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!new_arr[word_index])
			return (custom_clean_all(new_arr, word_index));
		ft_strlcpy(new_arr[word_index], &s[start], word_len + 1);
		word_index++;
	}
	new_arr[word_index] = NULL;
	return (new_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**new_arr;

	if (!s)
		return (NULL);
	new_arr = (char **)malloc(sizeof(char *) * (custom_count_words(s, c) + 1));
	if (!new_arr)
		return (NULL);
	return (custom_split_arr_fill(new_arr, s, c));
}
