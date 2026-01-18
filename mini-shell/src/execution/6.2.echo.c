/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.2.echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:36:22 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/12/31 18:21:40 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_echo(t_cmd *cmd)
{
	int	i;
	int	new_line;

	i = 1;
	new_line = 1;
	if (cmd->args[1] && ft_strcmp(cmd->args[1], "-n") == 0)
	{
		i = 2;
		new_line = 0;
	}
	while (cmd->args[i])
	{
		ft_putstr_fd(cmd->args[i], 1);
		if (cmd->args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (new_line)
		ft_putstr_fd("\n", 1);
	return (SUCCESS);
}
