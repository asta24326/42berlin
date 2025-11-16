#include <unistd.h>
#include <stdio.h>


int	ft_atoi(char *str);
void	ft_putnbr_base(int num, char *base);

int	main(int argc, char *argv[])
{
	char	*base;
	int	num;
	
	base = "0123456789abcdef";
	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		ft_putnbr_base(num, base);		
		return (write(1, "\n", 1), 0);
	}
	write(1, "\n", 1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	long	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
 		result = (result * 10) + (str[i++] - '0');
	return (result * sign);
}

void	ft_putnbr_base(int num, char *base)
{
	char	c;
	int		i;
	long	lnb;

	lnb = num;
	if (lnb < 0)
	{
		write(1, "-", 1);
		lnb *= -1;
	}
	if (lnb >= 16)
		ft_putnbr_base(lnb / 16, base);
	c = base[lnb % 16];
	write(1, &c, 1);
}

