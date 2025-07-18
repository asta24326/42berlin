/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:47:04 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 12:27:14 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <limits.h>

int main(void)
{
	char	*result;
	int		n;

	n = 0;
	result = ft_itoa(n);
	printf("%s\n", result);
	free(result);
	
	n = -0;
	result = ft_itoa(n);
	printf("%s\n", result);
	free(result);

	n = -423;
	result = ft_itoa(n);
	printf("%s\n", result);
	free(result);

	n = 423;
	result = ft_itoa(n);
	printf("%s\n", result);
	free(result);

	n = INT_MIN;
	result = ft_itoa(n);
	printf("%s\n", result);
	free(result);

	n = INT_MAX;
	result = ft_itoa(n);
	printf("%s\n", result);
	free(result);

	return (0);
}
*/

size_t	custom_int_len(long nb)
{
	size_t	int_len;

	int_len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb *= -1;
	while (nb)
	{
		int_len++;
		nb /= 10;
	}
	return (int_len);
}

char	*custom_itoa_arr_fill(char *result, long nb, int sign, size_t int_len)
{
	int		i;

	result[int_len] = '\0';
	i = int_len - 1;
	if (nb == 0)
	{
		result[i] = '0';
		return (result);
	}
	while (nb)
	{
		result[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	if (sign)
		result[i] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	int_len;
	long	long_nb;
	int		sign;

	long_nb = n;
	sign = 0;
	int_len = custom_int_len(long_nb);
	if (n < 0)
	{
		int_len++;
		sign = 1;
		long_nb *= -1;
	}
	result = (char *)malloc(sizeof(char) * (int_len + 1));
	if (!result)
		return (NULL);
	return (custom_itoa_arr_fill(result, long_nb, sign, int_len));
}
