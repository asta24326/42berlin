/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 22:26:29 by asharafe          #+#    #+#             */
/*   Updated: 2025/10/21 22:41:09 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_arr(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	ft_custom_exit(char *exit_msg)
{
	ft_putstr_fd(exit_msg, 2);
	exit (1);
}

int	ft_valid_pid(pid_t pid)
{
	if (pid == -1)
	{
		ft_putstr_fd("pipex: error fork failed\n", 2);
		return (1);
	}
	return (0);
}
