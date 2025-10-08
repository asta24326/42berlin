#include <stdio.h>
#include <unistd.h>

int	ft_int_len(int num);

int	main(void)
{
	int	test;

	test = 123;
	printf("%d, \n", test);
	printf("%d, \n", ft_int_len(test));
	return (0);
}

int	ft_int_len(int num)
{
	int	i;

	i = 0;
	while (num / 10)
	{
		i++;
		num = num / 10;
	}
	i++;
	return(i);
}