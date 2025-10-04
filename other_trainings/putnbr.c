
#include <unistd.h>
#include <stdio.h>

void	putnbr(int number);
int		atoi(char *s);


int	main(int argc, char *argv[])
{
	int	number;

	(void)argc;

	number = atoi(argv[1]);
	printf("%d\n", number);
	putnbr(number);
	return (1);
}

void	putnbr(int number)
{
	char	c;
	long	lnb;

	if (number == 0)
		{
			write(1, "0\n", 2);
			return ;
		}
	lnb = number;
	if (lnb < 0)
	{
		write(1, "-", 1);
		lnb *= -1;
	}
	if (lnb >= 10)
		putnbr(lnb / 10);
	c = (lnb % 10) + '0';
	write(1, &c, 1);
}

int	atoi(char *s)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (!*s)
		return (0);
	while ((*s >= '\t' && *s <= '\r') || (*s == ' '))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (result * sign);
}