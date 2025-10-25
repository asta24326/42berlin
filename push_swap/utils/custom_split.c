/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:45:25 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/09/20 23:09:18 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_words(char *s, char c);
static char	*extract_word(char *s, char c);
//
// #include <stdio.h>
// # include <unistd.h>
// # include <stdlib.h>
// # include <limits.h>
// # include <stdbool.h>
//
// char		**custom_split(char *s, char c);
// static int	count_words(char *s, char c);
// static char	*extract_word(char *s, char c);
// static char	**full_clean(char **arr, int words);
//
// int	main(void)
// {
// 	char	str[] = "Hello, World! Love You!";
// 	char	c = ' ';
// 	char	**new_arr;
// 	size_t	i;
//
// 	i = 0;
// 	new_arr = custom_split(str, c);
// 	if (!new_arr)
// 		return (printf("Memory allocation failed\n"), 1);
// 	printf("Original: %s\n", str);
// 	while (new_arr[i] != NULL)
// 		printf("%s\n", new_arr[i++]);
// 	i = 0;
// 	while (new_arr[i] != NULL)
// 		free (new_arr[i++]);
// 	return (free (new_arr), 0);
// }

char	**custom_split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 1));
	if (!result_array)
		return (NULL);
	while (i < words_count)
	{
		result_array[i] = extract_word(s, c);
		if (!result_array)
			return (full_free(NULL, result_array, 1), NULL);
		i++;
	}
	result_array[i] = NULL;
	return (result_array);
}

static int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			s++;
		while (*s && (*s != c))
		{
			if (inside_word == false)
			{
				count++;
				inside_word = true;
			}
			s++;
		}
	}
	return (count);
}

static char	*extract_word(char *s, char c)
{
	static int	cursor = 0;
	char		*word;
	int			word_len;
	int			i;

	word_len = 0;
	i = 0;
	while (s[cursor] == c)
		cursor++;
	while ((s[cursor + word_len] != c) && (s[cursor + word_len]))
		word_len++;
	word = malloc((size_t)word_len * sizeof(char) + 1);
	if (!word)
		return (NULL);
	while (s[cursor] != c && s[cursor])
		word[i++] = s[cursor++];
	word[i] = '\0';
	return (word);
}
