/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:55:17 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/06/19 12:13:15 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <unistd.h>
#include <stdio.h>

int	ft_isalnum(int c);

int	main(void)
{
		printf("%d\n", ft_isalnum(-255));
		return (0);
}
*/

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
