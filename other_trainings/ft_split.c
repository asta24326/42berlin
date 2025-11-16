#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void	ft_putstr(char *s);
int		ft_strlcpy(char *dst, char *src, int len);
int		count_words(char *str);
void	clean(char **result, int word_index);
char	**arr_fill(char **result, char *str);
char	**ft_split(char *str);

int	main(int argc, char **argv)
{
	char	**result;
	int		i;

	i = 0;
	if (argc == 2)
	{
		if (!argv[1][0])
		{
			ft_putstr("Empty string");
			return (1);
		}
		result = ft_split(argv[1]);
		while (result[i])
		{
			ft_putstr(result[i]);
			i++;
		}
		i = 0;
		while (result[i])
			free(result[i++]);
		free(result);
	}
	return (0);
}

char	**ft_split(char *str)
{
	char	**result;
	
	if (!str)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	if (!result)
		return (NULL);
	result = arr_fill(result, str);
	return (result);
}

int	count_words(char *str)
{
	int		words_count;
	int		inside_word;
	int		i;

	words_count = 0;
	i = 0;
	while (str[i])
	{
		inside_word = 0;
		while (str[i] && str[i] <= ' ')
			i++;;
		while (str[i] && str[i] > ' ')
		{
			if (inside_word == 0)
			{
				words_count++;
				inside_word = 1;
			}
			i++;
		}
	}
	return (words_count);
}

char	**arr_fill(char **result, char *str)
{
	int	i;
	int	start;
	int	word_len;
	int	word_index;

	i = 0;
	word_index = 0;
	while (str[i])
	{
		while (str[i] && str[i] <= ' ')
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] && !(is_delim(str[i])))
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

int	ft_strlcpy(char *dst, char *src, int len)
{
	int	i;
	int	src_len;

	src_len = 0;
	i = 0;
	while(src[i])
	{
		src_len++;
		i++;
	}
	i = 0;
	if (len > 0)
	{
		while (src[i] && (i < (len - 1)))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

void	ft_putstr(char *s)
{
	if (!*s)
		return ;
	while (*s)
		write(1, s++, 1);
	write(1, "\n", 1);
}
