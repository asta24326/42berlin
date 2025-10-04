#include <unistd.h>
#include <stdio.h>

int	is_valid(int char_to_check, int baselen);
int	ft_atoi_base(const char *str, int str_base);

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	
	if (argc == 3)
	{
		printf("%d\n", ft_atoi_base(argv[1], ft_atoi_base(argv[2], 10)));
		return (0);
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
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

	while (str[i] && is_valid(str[i], str_base))
	{
		result = result * str_base;

		if (str[i] >= '0' && str[i] <= '9')
			result = result + (str[i] - '0');
	
		else if (str[i] >= 'a' && str[i] <= 'f')
			result = result + (str[i] - 'a' + 10);
	
		else if (str[i] >= 'A' && str[i] <= 'F')
			result = result + (str[i] - 'A' + 10);
		i++;
	}
 	return (result * sign);
}

int	is_valid(int char_to_check, int str_base)
{
	char *lc_base;
	char *uc_base;
	int	i;

	i = 0;
	lc_base = "0123456789abcdef";
	uc_base = "0123456789ABCDEF";
	
	while (i < str_base)
	{
		if (char_to_check == lc_base[i] || char_to_check == uc_base[i])
			return (1);
		i++;
	}
	return (0);
}

