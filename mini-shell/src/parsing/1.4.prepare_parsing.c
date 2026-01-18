/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.4.prepare_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:06:57 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/06 13:08:52 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_pipe_count(char *copy)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	while (copy[++i])
		if (copy[i] == '|')
			count++;
	return (count);
}
