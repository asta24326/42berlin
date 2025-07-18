/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:39:56 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:52:24 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);

int	main(void)
{
	char			*big;
	char			*little;

	big = "Hello wor world!";
	little = "wor";
	printf("Word found fully: %s\n", ft_strnstr(big, little, 13));
	return (0);
}
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[j] && j < len)
	{
		i = 0;
		if (big[j] == little[i])
		{
			while ((little[i] && big[j + i]) && (j + i < len))
			{
				if (little[i] != big[j + i])
					break ;
				i++;
			}
			if (little[i] == '\0')
				return ((char *)&big[j]);
		}
		j++;
	}
	return (NULL);
}
