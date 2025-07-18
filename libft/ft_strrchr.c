/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:28:59 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:52:32 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

char	*ft_strrchr(const char *s, int c);

int	main(void)
{
	char *s = "Hello a world!";
	printf("%p\n", s + 1);
	printf("%p\n", ft_strrchr(s, 99));
	return (0);
}
*/

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char) c)
			last = s;
		s++;
	}
	if ((unsigned char) c == '\0')
		return ((char *)s);
	return ((char *) last);
}
