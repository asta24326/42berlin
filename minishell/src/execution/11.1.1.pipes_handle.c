/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11.1.1.pipes_handle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:38:44 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/02 23:13:43 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pipes_init(t_shell *shell)
{
	int	i;

	if (shell->pipes != NULL)
		ft_cleanup_pipes_array(shell);
	if (shell->pipe_count <= 0)
		return (SUCCESS);
	shell->pipes = calloc(shell->pipe_count, sizeof(int *));
	if (!shell->pipes)
		return (ft_putstr_fd("malloc failed", 2), FAILURE);
	i = -1;
	while (++i < shell->pipe_count)
	{
		shell->pipes[i] = calloc(2, sizeof(int));
		if (!shell->pipes[i])
		{
			ft_cleanup_pipes_array(shell);
			return (ft_putstr_fd("malloc failed", 2), FAILURE);
		}
		if (pipe(shell->pipes[i]) == -1)
		{
			ft_cleanup_pipes_array(shell);
			return (ft_putstr_fd("piping failed", 2), FAILURE);
		}
	}
	return (SUCCESS);
}

void	ft_setup_pipes_for_cmd(t_shell *shell, t_cmd *cmd, int cmd_index)
{
	if (!shell || !shell->pipes)
		return ;
	if (cmd->skip_in_pipe == false && cmd_index > 0)
	{
		dup2(shell->pipes[cmd_index - 1][0], STDIN_FILENO);
		close(shell->pipes[cmd_index - 1][0]);
	}
	if (cmd->skip_out_pipe == false && cmd_index < shell->pipe_count)
	{
		dup2(shell->pipes[cmd_index][1], STDOUT_FILENO);
		close(shell->pipes[cmd_index][1]);
	}
	ft_close_unused_child_pipes(shell, cmd_index);
}

void	ft_close_all_pipes(t_shell *shell)
{
	int	i;

	if (!shell || !shell->pipes)
		return ;
	i = -1;
	while (++i < shell->pipe_count)
	{
		if (shell->pipes[i])
		{
			if (shell->pipes[i][0] != -1)
			{
				close(shell->pipes[i][0]);
				shell->pipes[i][0] = -1;
			}
			if (shell->pipes[i][1] != -1)
			{
				close(shell->pipes[i][1]);
				shell->pipes[i][1] = -1;
			}
		}
	}
}

void	ft_cleanup_pipes_array(t_shell *shell)
{
	int	i;

	if (!shell || !shell->pipes)
		return ;
	i = -1;
	while (++i < shell->pipe_count)
	{
		free(shell->pipes[i]);
		shell->pipes[i] = NULL;
	}
	free(shell->pipes);
	shell->pipes = NULL;
	shell->pipe_count = 0;
}

void	ft_close_unused_child_pipes(t_shell *shell, int child_index)
{
	int	i;

	i = -1;
	while (++i < shell->pipe_count)
	{
		if (i == child_index - 1)
		{
			close (shell->pipes[i][1]);
		}
		else if (i == child_index)
		{
			close(shell->pipes[i][0]);
		}
		else
		{
			close(shell->pipes[i][0]);
			close(shell->pipes[i][1]);
		}
	}
}
