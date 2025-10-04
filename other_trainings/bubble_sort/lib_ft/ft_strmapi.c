/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:52:15 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:52:16 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	to_upper(unsigned int i, char c);
char	to_lower(unsigned int i, char c);
size_t	ft_strlen(const char *s);

int	main(void)
{
	char	*result;
	char	*src = "Hello World! 1234";

	result = ft_strmapi(src, to_upper);
	
	printf("Before: %s\n", src);
	printf("After: %s\n", result);
	free(result);

	result = ft_strmapi(src, to_lower);
	printf("Before: %s\n", src);
	printf("After: %s\n", result);
	free(result);

	return (0);
}

char	to_upper(unsigned int i, char c)
{
	(void)i;

	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

char	to_lower(unsigned int i, char c)
{
	(void)i;

	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return(i);
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	if (!s || !f)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
