/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:42:48 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:47:26 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

int	ft_isprint(int c);

int	main(void)
{
		printf("%d\n", ft_isprint('A'));
		return (0);
}
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
