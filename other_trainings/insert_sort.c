#include <stdio.h>
#include <unistd.h>

void	insert_sort(int	*tab, unsigned int size);


int	main(void)
{
	int				tab[] = {64, 34, 25, 12, 22, 11, 1};
	unsigned int	size;
	int				i;
	size = 7;
	printf("Before\n");
	i = 0;
	while (i <= 6)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	insert_sort(tab, size);
	printf("After\n");
	i = 0;
	while (i <= 6)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}

void	insert_sort(int	*tab, unsigned int size)
{
	int	i;
	int	j;
	int	current;

	i = 1;
	while (i <= size - 1)
	{
		current = tab[i];
		j = i;
		while (j > 0 && tab[j - 1] > current)
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = current;
		i++;
	}
}