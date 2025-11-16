#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

void	ft_putstr(char *s);
char	**ft_split(char *s);
int	ft_count_words(char *s);
char	*ft_strcpy(char *dest, char *src, int len);
void	ft_full_clean(char **s, int word_index);


int	main(int ac, char **av)
{
	char	**res;
	int	i;	

	i = 1;
	if (ac == 2)
	{
		res = ft_split(av[1]);
		while (res[i])
		{
			ft_putstr(res[i]);
			ft_putstr(" ");
			i++;
		}
		ft_putstr(res[0]);
	}
	ft_putstr("\n");
	return (0);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s++, 1);
	}
}

char	**ft_split(char *s)
{
	char **res;
	int	i;
	int	start;
	int	words_count;
	int	word_index;

	words_count = ft_count_words(s);
	printf("words: %d\n", words_count);
	res = malloc(sizeof(char *) * (words_count + 1));
	if(!res)
		return (NULL);
	res[words_count] = NULL;
	
	word_index = 0;
	start = 0;
	i = 0;
	while (word_index <= words_count - 1)
	{
		while (s[i] <= ' ')
			i++;
		start = i;
		while (s[i] > ' ')
			i++;
		res[word_index] = malloc(sizeof(char) * (i - start + 1));
		if (!(res[word_index]))
		{
			ft_full_clean(res, word_index);
			return (NULL);
		}
		res[word_index] = ft_strcpy(res[word_index], &s[start], i - start);
		word_index++;
	}
	return (res);
}

void	ft_full_clean(char **s, int word_index)
{
	while(word_index >= 0)
	{
		free(s[word_index]);
		word_index--;
	}
	free(s);
}

char	*ft_strcpy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_count_words(char *s)
{
	int	i;
	int	inside_word;
	int	words_count;

	i = 0;
	inside_word = 0;
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
