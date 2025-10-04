#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

unsigned int	ft_atoi(char *s);
unsigned int	lcm(unsigned int a, unsigned int b);

int	main(int argc, char *argv[])
{
	if (ft_atoi(argv[1]) == 0 || ft_atoi(argv[2]) == 0)
		return (0);
	printf("%d\n", lcm(ft_atoi(argv[1]), ft_atoi(argv[2])));	
	return (0);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	lcm;
	
	if (a > b)
		lcm = a;
	else
		lcm = b;		
	while (1)
	{
		if ((lcm % a == 0) && (lcm % b == 0))
			return (lcm);
		lcm++;
	}
}

unsigned int	ft_atoi(char *s)
{
	unsigned int	result;
	int	i;
	unsigned int	sign;
	
	i = 0;
	result = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-' && s[i] == '+')
	 	i++;
	while (s[i] >= '0' && s[i] <= '9')
		result = (result * 10) + (s[i++] - '0');
	return (result * sign);
}

