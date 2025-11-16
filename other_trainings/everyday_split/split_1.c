#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_count_words(char *s);
void	ft_putstr(char *s);
char	**ft_split(char *s);
void	ft_custom_copy(char *dest, char *src, int len);
void	ft_custom_free(char **res, int word_index);
char	**ft_fill_arr(char **res, char *s);


int	main(int ac, char **av)
{
	char	**res;
	int		i;

	i = 1;
	printf("words count: %i\n", ft_count_words(av[1]));
	if (ac == 2)
	{
		res = ft_split(av[1]);
		if (ft_count_words(av[1]) == 1)
		{
			ft_putstr(res[0]);
		}
		else
		{
			while (res[i])
			{
				ft_putstr(res[i]);
				ft_putstr(" ");
				i++;
			}
			ft_putstr(res[0]);
		}
	}
	ft_putstr("\n");
	return (0);
}

char	**ft_split(char *s)
{
	char	**res;
	int		words_count;

	if (!*s)
		return (NULL);
	words_count = ft_count_words(s);
	res = malloc(sizeof(char *) * (words_count + 1));
	if (!res)
		return (NULL);
	res = ft_fill_arr(res, s);
	return(res);
}

int	ft_count_words(char *s)
{
	int		i;
	int		words_count;
	int		inside_word;

	i = 0;
	words_count = 0;
	while (s[i])
	{
		inside_word = 0;
		while (s[i] && s[i] <= ' ')
			i++;
		while (s[i] && s[i] > ' ')
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

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

char	**ft_fill_arr(char **res, char *s)
{
	int		i;
	int		word_len;
	int		word_index;
	int		start; 

	word_index = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] <= ' ')
			i++;
		start = i;
		while (s[i] && s[i] > ' ')
			i++;
		word_len = i - start;
		res[word_index] = malloc(sizeof(char) * (word_len + 1));
		if(!res[word_index])
			ft_custom_free(res, word_index - 1);
		ft_custom_copy(res[word_index], &s[start], word_len);
		word_index++;
	}
	res[word_index] = NULL;
	return (res);
}

void	ft_custom_free(char **res, int word_index)
{
	while (word_index >= 0)
	{
		free(res[word_index]);
		word_index--;
	}
}

void	ft_custom_copy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (len > i)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
