#include <stdio.h>
#include <unistd.h>

int	ft_atoi(char *s);
void	ft_putnbr(int num);
int	is_prime(int num);

int	main(int argc, char **argv)
{
	int	number;
	int	result;

	result = 0;
	if (argc != 2)
		return ((write (1,"0\n", 2)), 0);
	number = ft_atoi(argv[1]);
	if (number <= 0)
		return ((write (1,"0\n", 2)), 0);
	while (number > 1)
	{
		if (is_prime(number))
			result += number;
		number--;
	}
	ft_putnbr(result);
	write (1, "\n", 1);
	return (0);
}

int	ft_atoi(char *s)
{
	long	result;
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	result = 0;
	while ((s[i] >= '\t' && s[i] <= '\r') || (s[i] == ' '))
		i++;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign *= -1;
	while (s[i] >= '0' && s[i] <= '9')
	{	
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	return (result * sign);
}

void	ft_putnbr(int num)
{
	char	c;
	long	lnb;

	lnb = num;
	if (lnb < 0)
	{
		write(1, "-", 1);
		lnb *= -1;
	}
	if (lnb >= 10)
		ft_putnbr(lnb / 10);
	c = (lnb % 10) + '0';
	write(1, &c, 1);
}

int	is_prime(int num)
{
	if (num == 2)
		return (1);
	if (num % 2)
		return (1);
	return (0);
}
