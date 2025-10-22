/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:54:30 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/10/21 00:39:37 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>
// // #include <stdlib.h>
// // #include <stdbool.h>
// // #include <stdio.h>

// void	ft_putstr(char *s);
// int		ft_strlcpy(char *dst, const char *src, int len);
int		count_words(const char *str, char delim);
void	clean(char **result, int word_index);
char	**arr_fill(char **result, const char *str, char delim);
char	**ft_split(const char *str, char delim);
//
// int	main(int argc, char **argv)
// {
// 	char	**result;
// 	int		i;

// 	i = 0;
// 	if (argc == 3)
// 	{
// 		if (!argv[1][0])
// 			return (ft_putstr_fd("Empty string!\n", 1), 1);
// 		result = ft_split(argv[1], argv[2][0]);
// 		while (result[i])
// 		{
// 			ft_putstr_fd(result[i], 1);
// 			i++;
// 		}
// 		i = 0;
// 		while (result[i])
// 			free(result[i++]);
// 		free(result);
// 	}
// 	return (0);
// }

char	**ft_split(const char *str, char delim)
{
	char	**result;

	if (!str)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(str, delim) + 1));
	if (!result)
		return (NULL);
	return (arr_fill(result, str, delim));
}

int	count_words(const char *str, char delim)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str && *str == delim)
			str++;
		while (*str && *str != delim)
		{
			if (inside_word == false)
			{
				count++;
				inside_word = true;
			}
			str++;
		}
	}
	return (count);
}

char	**arr_fill(char **result, const char *str, char delim)
{
	int	i;
	int	start;
	int	word_len;
	int	word_index;

	i = 0;
	word_index = 0;
	while (str[i])
	{
		while (str[i] && str[i] == delim)
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] && str[i] != delim)
			i++;
		word_len = i - start;
		result[word_index] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!result[word_index])
			return (clean(result, word_index), NULL);
		ft_strlcpy(result[word_index], &str[start], word_len + 1);
		word_index++;
	}
	result[word_index] = NULL;
	return (result);
}

void	clean(char **result, int word_index)
{
	while (word_index > 0)
	{
		word_index--;
		free(result[word_index]);
	}
	free(result);
}

// int	ft_strlcpy(char *dst, const char *src, int len)
// {
// 	int	i;
// 	int	src_len;

// 	src_len = 0;
// 	i = 0;
// 	while(src[i])
// 	{
// 		src_len++;
// 		i++;
// 	}
// 	i = 0;
// 	if (len > 0)
// 	{
// 		while (src[i] && (i < (len - 1)))
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	return (src_len);
// }

// void	ft_putstr(char *s)
// {
// 	if (!*s)
// 		return ;
// 	while (*s)
// 		write(1, s++, 1);
// 	write(1, "\n", 1);
// }