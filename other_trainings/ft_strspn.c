#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strspn(char *str, char *accept);
size_t	ft_strcspn(char *str, char *reject);

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		// printf("%zu\n", ft_strspn(argv[1], argv[2]));
		// printf("Std %zu\n", strspn(argv[1], argv[2]));
		printf("%zu\n", ft_strcspn(argv[1], argv[2]));
		printf("Std %zu\n", strcspn(argv[1], argv[2]));
	}
	return (0);
}

size_t	ft_strspn(char *str, char *accept)
{
	size_t	i;
	size_t	j;
	int		check;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		j = 0;
		check = 0;
		while (accept[j])
		{
			if (str[i] == accept[j])
				check = 1;
			j++;
		}
		if (check == 0)
			return (i);
		i++;
	}
	return (i);
}

size_t	ft_strcspn(char *str, char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		j = 0;
		while (reject[j])
		{
			if (str[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
