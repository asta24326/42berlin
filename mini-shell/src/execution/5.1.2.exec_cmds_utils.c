/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.1.2.exec_cmds_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:04:25 by asharafe          #+#    #+#             */
/*   Updated: 2026/01/08 00:49:20 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_wait_for_childs(t_shell *shell, int *status, int expected_childs)
{
	int		i;
	pid_t	pid;
	int		child_status;

	i = -1;
	while (++i < expected_childs)
	{
		pid = wait(&child_status);
		if (pid == -1)
		{
			ft_putstr_fd("wait failed", 2);
			break ;
		}
		if (pid == shell->last_pid)
		{
			if (WIFEXITED(child_status))
				shell->exit_status = WEXITSTATUS(child_status);
			else if (WIFSIGNALED(child_status))
				shell->exit_status = 128 + WTERMSIG(child_status);
		}
	}
	*status = child_status;
}

void	ft_handle_cat(t_shell *shell)
{
	int	dev_null;

	dev_null = 0;
	if (shell->pipe_count >= 1 && shell->cmd->index == 0 
		&& shell->cmd->next->index == 1
		&& !shell->cmd->args[1]
		&& ft_strcmp(shell->cmd->args[0], "cat") == 0)
	{
		dev_null = open("/dev/null", O_WRONLY);
		if (dev_null != -1)
		{
			dup2(dev_null, STDERR_FILENO);
			close(dev_null);
		}
	}
}
