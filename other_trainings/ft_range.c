#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end);
int	ft_atoi(char *s);
void	ft_putnbr(int num);
int	ft_range_len(int start, int end);

int	main(int argc, char *argv[])
{
	int	*arr;
	int	i;
	int	range_len;

	range_len = ft_range_len(ft_atoi(argv[1]), ft_atoi(argv[2]));
	i = 0;
	if (argc == 3)
		arr = ft_range(ft_atoi(argv[1]), ft_atoi(argv[2]));
	while (i < range_len)
	{
		ft_putnbr(arr[i++]);
		write(1, "\n", 1);
	}
	free(arr);
	return (0);
}

int	ft_range_len(int start, int end)
{
	int range_len;

	if ((end - start) < 0)
		range_len = ((end - start) * -1) + 1;
	else
		range_len = (end - start) + 1;
	return (range_len);
}

int	*ft_range(int start, int end)
{
	int	*arr;
	int	range_len;
	int	temp;
	int	i;

	temp = start;
	range_len = 0;
	i = 0;
	range_len = ft_range_len(start, end);	
	arr = (int *)malloc(sizeof(int) * range_len);
	if (!arr)
		return (0);
	while (range_len > i)
	{
		if (start < end)
			arr[i] = start++;
		else
			arr[i] = start--;
		i++;
	}
	return (arr);
}

int	ft_atoi(char *s)
{
	int	 i;
	int	result;
	int	sign;
	
	i = 0;
	result = 0;
	sign = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{	
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		result = (result * 10) + (s[i++] - '0');
	return (result * sign);
}

void	ft_putnbr(int num)
{
	long	lnb;
	char	c;

	lnb = num;
	if (lnb < 0)
	{
		write(1, "-", 1);
		lnb *= -1;
	}
	if (lnb >= 10)
		ft_putnbr(lnb / 10);
	c = (lnb % 10) + '0';
	write (1, &c, 1);
}
