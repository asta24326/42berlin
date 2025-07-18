/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:34:22 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 12:08:23 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <unistd.h>
#include <stdio.h>

int	ft_isascii(int c);

int	main(void)
{
		printf("%d\n", ft_isascii(-255));
		return (0);
}
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
