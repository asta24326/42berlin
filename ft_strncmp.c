/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:41:50 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 12:12:43 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	main(void)
{
	char			*src;
	char			*dest;
	int				result;
	unsigned int	n;

	src = "1234 567";
	dest = "1234567";
	n = 5;
	result = ft_strncmp(src, dest, n);
	if (result == 0)
		printf("Strings are equal!\n");
	if (result > 0)
		printf("Src is greater that dest!\n");
	if (result < 0)
		printf("Dest is greater that src!\n");
	return (0);
}
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
