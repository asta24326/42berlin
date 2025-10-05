#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int	is_delim(char c);
void	ft_putstr(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t len);
size_t	count_words(char *str);
void	clean(char **result, size_t word_index);
char	**arr_fill(char **result, char *str);
char	**ft_split(char *str);

int	main(int argc, char **argv)
{
	char	**result;
	int		i;

	i = 0;
	if (argc == 2)
	{
		result = ft_split(argv[1]);
		while (result[i])
		{
			ft_putstr(result[i]);
			i++;
		}
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
	return (arr_fill(result, str));
}

int	is_delim(char c)
{
	if (c <= 13 || c == 32)
		return (1);
	return (0);
}

size_t	count_words(char *str)
{
	int	count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (is_delim(*str))
			str++;
		while (*str && !is_delim(*str))
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

char	**arr_fill(char **result, char *str)
{
	size_t	i;
	size_t	start;
	size_t	word_len;
	size_t	word_index;

	i = 0;
	word_index = 0;
	while (str[i])
	{
		while (is_delim(str[i]))
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] && !is_delim(str[i]))
			i++;
		word_len = i - start;
		result[word_index] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!result[word_index])
			return (clean(result, word_index--), NULL);
		ft_strlcpy(result[word_index], &str[start], word_len + 1);
		word_index++;
		i++;
	}
	result[word_index] = NULL;
	return (result);
}

void	clean(char **result, size_t word_index)
{
	while (word_index >= 0)
		free(result[word_index--]);
	free(result);
}

size_t	ft_strlcpy(char *dst, char *src, size_t len)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	i = 0;	
	while(*src)
		src_len++;
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
		write(1, &(*s), 1);
}

