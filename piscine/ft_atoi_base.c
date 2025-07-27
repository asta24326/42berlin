/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:28:08 by asharafe          #+#    #+#             */
/*   Updated: 2025/04/13 02:35:34 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_char_i(char *str, char to_find);
int	ft_atoi_base(char *str, char *base);
int	ft_base_len(char *base, char *str);
int	ft_if_duplicate(char *string);
int	ft_valid_base(char *base, int base_len);
/*
int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Put imput");
		return (1);
	}
	printf("%i", ft_atoi_base(argv[1], argv[2]));
}
*/

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	i;
	int	base_len;

	result = 0;
	i = 0;
	sign = 1;
	base_len = ft_base_len(base, str);
	if (ft_valid_base(base, base_len) || ft_if_duplicate(base))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_char_i(base, str[i]) >= 0)
	{
		result = result * base_len + (ft_char_i(base, str[i]));
		i++;
	}
	return (sign * result);
}

int	ft_base_len(char *base, char *str)
{
	int	i;
	int	j;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' ')
		|| (str[i] == '+') || (str[i] == '-'))
		i++;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
				break ;
			j++;
		}
		if (!base[j])
			return (0);
		i++;
	}
	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_char_i(char *str, char to_find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_valid_base(char *base, int base_len)
{
	if (base_len <= 1 || ft_char_i(base, '\n') >= 0
		|| ft_char_i(base, ' ') >= 0
		|| ft_char_i(base, '\r') >= 0
		|| ft_char_i(base, '\t') >= 0
		|| ft_char_i(base, '\v') >= 0
		|| ft_char_i(base, '\f') >= 0
		|| ft_char_i(base, '+') >= 0
		|| ft_char_i(base, '-') >= 0)
		return (1);
	return (0);
}

int	ft_if_duplicate(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
