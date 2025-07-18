/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:11:00 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/06/19 11:48:37 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <unistd.h>
#include <stdio.h>

int	ft_islower(int c);

int	main(void)
{
		printf("%d\n", ft_isupper(-255));
		return (0);
}
*/

int	ft_islower(int c)
{
	return ((unsigned char) c >= 'a' && (unsigned char) c <= 'z');
}
