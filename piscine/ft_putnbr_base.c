/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:37:13 by asharafe          #+#    #+#             */
/*   Updated: 2025/07/25 21:05:36 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
int		ft_base_valid(char *str);
int		ft_base_len(char *str);
int		ft_find_i(char *str, char to_find);
void	ft_int_min(int nbr, char *base);
/*
int	main(void)
{
	write(1, "Case 1: ", 8);
	ft_putnbr_base(42, "0123456789");
	write(1, "\n", 1);
	
	write(1, "Case 2: ", 8);
	ft_putnbr_base(42, "0123456789ABCDEF");
	write(1, "\n", 1);

	write(1, "Case 3: ", 8);
	ft_putnbr_base(42, "poneyvif");
	write(1, "\n", 1);

	write(1, "Case 4: ", 8);
	ft_putnbr_base(42, "0124562789");
	write(1, "\n", 1);

	write(1, "Case 5: ", 8);
	ft_putnbr_base(42, "0123456789abcdef");
	write(1, "\n", 1);

	write(1, "Case 6: ", 8);
	ft_putnbr_base(42, "Poneyvif");
	write(1, "\n", 1);

	write(1, "Case 7: ", 8);
	ft_putnbr_base(-42, "0123456789");
	write(1, "\n", 1);

	write(1, "Case 8: ", 8);
	ft_putnbr_base(-42, "0123456789ABCDEF");
	write(1, "\n", 1);

	write(1, "Case 9: ", 8);
	ft_putnbr_base(-42, "poneyvif");
	write(1, "\n", 1);

	write(1, "Case 10: ", 9);
	ft_putnbr_base(2147483647, "0123456789");
	write(1, "\n", 1);

	write(1, "Case 11: ", 9);
	ft_putnbr_base(-2147483648, "0123456789");
	write(1, "\n", 1);
	
	write(1, "Case 12: ", 9);
	ft_putnbr_base(42, "AidarBes");
	write(1, "\n", 1);

	return (0);
}
*/

void	ft_putnbr_base(int nbr, char *base)
{
	char	digit;
	int		i;

	i = 0;
	if ((!ft_base_valid(base)) || (!ft_base_len(base)))
		return ;
	if (nbr == (-2147483648))
	{
		write (1, "-", 1);
		ft_int_min(2147483648 / ft_base_len(base), base);
		digit = base[(2147483648 % ft_base_len(base))];
		write(1, &digit, 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= ft_base_len(base))
		ft_putnbr_base((nbr / ft_base_len(base)), base);
	digit = base[(nbr % ft_base_len(base))];
	write(1, &digit, 1);
}

int	ft_base_valid(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		if ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_base_len(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_int_min(int nbr, char *base)
{
	char	digit;

	if (nbr >= ft_base_len(base))
		ft_int_min(nbr / ft_base_len(base), base);
	digit = base[nbr % ft_base_len(base)];
	write(1, &digit, 1);
}

