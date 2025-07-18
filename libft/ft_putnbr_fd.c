/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:51:10 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:51:11 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	ft_putnbr_fd(int n, int fd);

int	main(void)
{
	ft_putnbr_fd(10, 1);
	return (0);
}
*/

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	l_nbr;

	l_nbr = n;
	if (l_nbr < 0)
	{
		l_nbr *= -1;
		write(fd, "-", 1);
	}
	if (l_nbr >= 10)
		ft_putnbr_fd((l_nbr / 10), fd);
	c = (l_nbr % 10) + '0';
	write(fd, &c, 1);
}
