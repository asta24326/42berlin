/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:11:26 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/07/25 18:58:37 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

size_t	ft_strlen(const char *s);

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
	{
		printf("No or more than 1 argument!\n");
		return (0);
	}
	printf("Length is: %i\n", (ft_strlen(argv[1])));
	return (0);
}
*/

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}
