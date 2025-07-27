/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:11:30 by asharafe          #+#    #+#             */
/*   Updated: 2025/04/15 00:15:57 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_args(int arguments, char **argv);
int		ft_strcmp(char *src, char *dest);
void	ft_swap(char **src, char **dest);

int	main(int argc, char **argv)
{
	int	i;
	int	swap_flag;

	if (argc == 1)
		return (0);
	i = 2;
	swap_flag = 1;
	while (swap_flag)
	{
		swap_flag = 0;
		while (argc > i)
		{
			if (ft_strcmp(argv[i - 1], argv[i]) > 0)
			{
				ft_swap(&argv[i - 1], &argv[i]);
				swap_flag++;
			}
			i++;
		}
		i = 2;
	}
	ft_print_args(argc, argv);
	return (0);
}

void	ft_print_args(int arguments, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (arguments > i)
	{
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

int	ft_strcmp(char *src, char *dest)
{
	while (*src && *dest && *src == *dest)
	{
		src++;
		dest++;
	}
	return (*src - *dest);
}

void	ft_swap(char **src, char **dest)
{
	char	*temp;

	temp = *src;
	*src = *dest;
	*dest = temp;
}
