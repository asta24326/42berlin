/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:51:51 by asharafe          #+#    #+#             */
/*   Updated: 2025/04/14 23:37:03 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	while (argc > 1)
	{
		ft_putstr(argv[argc - 1]);
		write (1, "\n", 1);
		argc--;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
