/*
Assignment name
: rev_wstr

Expected files
: rev_wsti.c

Allowed functions: write, malloc, free

Write a program that takes a string as a parameter, and prints its words in reverse order.
A "word" is a part of the string bounded by spaces and/or tabs, or the begin/end of the string.
If the number of parameters is different from 1, the program will display
'In'.

In the parameters that are going to be tested, there won't be any "additional" spaces (meaning that there won't be additionnal spaces at the beginning or at the end of the string, and words will always be separated by exactly one space).
Examples:
$› /rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e 
ironic? it Isn't gatherings. love I But people! hate You$ 

$>./rev_wstr "abcdefghijklm"
abcdefghijklm

$ /rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$

$ ./rev_wstr | cat -e

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

void	ft_putstr(char *s);
int		ft_count_words(char *s);
int		is_space(char s);
void	ft_putstr(char *s);


int	main(int argc, char **argv)
{
	char	**res;
	int		i;
	int		count_words;

	i = 0;
	// if (argc == 2)
	// 	res = rev_str(argv[1]);
	
	count_words = ft_count_words(argv[1]);
	printf("%d\n", count_words);
	ft_putstr("\n");
	free(res);
	return (0);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

char	**rev_str(char *s)
{
	int			i;
	char	**res;
	int		words;
	int		word_index;
	int		word_len;
	int		start;

	words = ft_count_words(s);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (ft_putstr("malloc error"), NULL);
	res[words] = NULL;
	word_index = 0;
	i = 0;
	while (*s)
	{
		while (*s && is_space(*s))
			s++;
		if (*s && !is_space(*s))

	}
}



int	ft_count_words(char *s)
{
	int	count_words;
	int	inside_word;

	count_words = 0;
	inside_word = 0;
	while (*s)
	{
		if (is_space(*s))
			inside_word = 0;
		else if (!inside_word)
		{
			inside_word = 1;
			count_words++;
		}
		s++;
	}
	return (count_words);
}


int	is_space(char s)
{
	if (s <= 13 || s == ' ')
		return (1);
	return (0);
}