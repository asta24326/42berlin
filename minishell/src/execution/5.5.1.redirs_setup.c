/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.5.1.redirs_setup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:44:31 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/05 19:37:03 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_setup_out_fd(t_shell *shell, t_cmd *cmd);
static void	ft_setup_in_fd(t_shell *shell, t_cmd *cmd);
static void	ft_setup_hdoc_in_fd(t_shell *shell, t_cmd *cmd);

void	ft_setup_cmd_redirs(t_shell *shell, t_cmd *cmd)
{
	if (cmd->redirs)
	{
		if (cmd->redirs->out_fd >= 0)
		{
			ft_setup_out_fd(shell, cmd);
			cmd->skip_out_pipe = true;
		}
		if (cmd->redirs->in_fd >= 0)
		{
			ft_setup_in_fd(shell, cmd);
			cmd->skip_in_pipe = true;
		}
		else if (cmd->redirs->hdocs)
		{
			ft_setup_hdoc_in_fd(shell, cmd);
			cmd->skip_in_pipe = true;
		}
	}
	ft_setup_pipes_for_cmd(shell, cmd, cmd->index);
}

static void	ft_setup_out_fd(t_shell *shell, t_cmd *cmd)
{
	if (shell->orig_stdout == -1)
		shell->orig_stdout = dup(STDOUT_FILENO);
	dup2(cmd->redirs->out_fd, STDOUT_FILENO);
	close(cmd->redirs->out_fd);
	cmd->redirs->out_fd = -1;
}

static void	ft_setup_in_fd(t_shell *shell, t_cmd *cmd)
{
	if (shell->orig_stdin == -1)
		shell->orig_stdin = dup(STDIN_FILENO);
	dup2(cmd->redirs->in_fd, STDIN_FILENO);
	close(cmd->redirs->in_fd);
	cmd->redirs->in_fd = -1;
}

static void	ft_setup_hdoc_in_fd(t_shell *shell, t_cmd *cmd)
{
	t_hdoc	*last_hdoc;

	last_hdoc = ft_get_last_hdoc(cmd->redirs->hdocs);
	if (!last_hdoc)
		ft_putstr_fd("ft_get_last_hdoc failed\n", 2);
	if (shell->orig_stdin == -1)
		shell->orig_stdin = dup(STDIN_FILENO);
	dup2(last_hdoc->hdoc_fd[0], STDIN_FILENO);
	close(last_hdoc->hdoc_fd[0]);
	last_hdoc->hdoc_fd[0] = -1;
}

void	ft_restore_orig_fds(t_shell *shell)
{
	if (shell->orig_stdin >= 0)
	{
		dup2(shell->orig_stdin, STDIN_FILENO);
	}
	if (shell->orig_stdout >= 0)
	{
		dup2(shell->orig_stdout, STDOUT_FILENO);
	}
}
