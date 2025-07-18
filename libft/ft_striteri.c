/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:51:49 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:51:50 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	to_upper(unsigned int i, char *c);
void	to_lower(unsigned int i, char *c);
size_t	ft_strlen(const char *s);

int	main(void)
{
	char	src_1[] = "Hello World! 1234";

	printf("Before: %s\n", src_1);
	ft_striteri(src_1, to_upper);
	printf("After(striteri_to_upper): %s\n", src_1);
	
	char	src_2[] = "Hello World! 1234";
	printf("Before: %s\n", src_2);
	ft_striteri(src_2, to_lower);
	printf("After(striteri_to_lower): %s\n", src_2);

	return (0);
}

void	to_upper(unsigned int i, char *c)
{
	(void)i;

	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

void	to_lower(unsigned int i, char *c)
{
	(void)i;

	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
