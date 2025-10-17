#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size);

int	main(void)
{
	int	i;
	int	tab[] = {1, 10, 22, 32, 3};

	i = 0;
	printf("Before\n");
	while (i <= 4)
	{
		printf("%i\n", tab[i]);
		i++;
	}
	sort_int_tab(tab, 5);
	printf("After\n");
	i = 0;
	while (i <= 4)
	{
		printf("%i\n", tab[i]);
		i++;
	}
	return (0);
}

void	sort_int_tab(int *tab, unsigned int size)
{
	int	tmp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i <= size - 2)
	{
		j = i;
		while (j <= size - 1)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}