#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstr(char *s);
int		ft_atoi(char *str);
char	*ft_itoa(int num);
char	*ft_strdup(char *str);
int		ft_strlen(char *s);
int		ft_int_len(int num);

int	main(int argc, char **argv)
{
	char	*res;

	if (argc == 2)
	{
		res = ft_itoa(ft_atoi(argv[1]));
		ft_putstr(res);
	}
	ft_putstr("\n");
	free (res);
	return (0);
}

int	ft_atoi(char *str)
{
	long	result;
	int		i;
	int		sign;

	sign = 1;
	result = 0;
	if (!*str)
		return (0);
	while (*str <= 13 || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				sign *= -1;
			str++;
		}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

char	*ft_itoa(int num)
{
	int		i;
	int		num_len;
	char	*res;
	long	lnb;

	num_len = ft_int_len(num);
	lnb = num;
	if (lnb == 0)
		return (ft_strdup("0"));
	res = (char *)malloc(sizeof(char) * (num_len + 1));
	if (!res)
		return (ft_putstr("Malloc error!"), NULL);
	res[num_len] = '\0';
	i = num_len - 1;
	if (lnb < 0)
	{
		res[0] = '-';
		lnb *= -1;
		while (i >= 1)
		{
			res[i] = lnb % 10 + '0';
			lnb /= 10;
			i--;
		}
		return (res);
	}
	while(i >= 0)
	{
		res[i] = lnb % 10 + '0';
		lnb /= 10;
		i--;
	}
	return (res);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

char	*ft_strdup(char *str)
{
	char	*res;
	int		i;

	i = 0;
	if (!*str)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!res)
		return (ft_putstr("Malloc error!"), NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

int	ft_int_len(int num)
{
	int	i;

	i = 0;
	if (num < 0)
		i++;
	while (num / 10)
	{
		i++;
		num = num / 10;
	}
	i++;
	return(i);
}
