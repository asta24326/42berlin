/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:35:26 by kschmitt          #+#    #+#             */
/*   Updated: 2025/12/18 11:10:26 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_arr(char **arr_split)
{
	int	i;

	i = 0;
	while (arr_split[i])
	{
		free(arr_split[i]);
		i++;
	}
	free(arr_split);
}
