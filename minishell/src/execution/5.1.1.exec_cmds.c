/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.1.1.exec_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:15:52 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/06 20:08:25 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_handle_cmds_redirs(t_shell *shell);
static void	ft_exec_solo_cmd(t_shell *shell, t_cmd *cmd);
static int	ft_exec_multi_cmds(t_shell *shell, t_cmd *cmd);
static void	ft_exec_child_multi(t_shell *shell, t_cmd *curr_cmd);

void	ft_exec_cmds(t_shell *shell)
{
	if (!shell->cmd)
		return ;
	if (ft_handle_cmds_redirs(shell) == FAILURE)
		return ;
	if (shell->cmd->next)
	{
		if (ft_pipes_init(shell) == FAILURE)
		{
			shell->exit_status = FAILURE;
			return ;
		}
		ft_adjust_pipes_for_skipped_cmds(shell);
		ft_exec_multi_cmds(shell, shell->cmd);
	}
	else
		ft_exec_solo_cmd(shell, shell->cmd);
}

static int	ft_handle_cmds_redirs(t_shell *shell)
{
	t_cmd	*curr_cmd;

	curr_cmd = shell->cmd;
	while (curr_cmd)
	{
		if (curr_cmd->redirs && curr_cmd->redirs->list)
		{
			if (handle_redirs(shell, curr_cmd) == FAILURE)
			{
				curr_cmd->has_redir_err = true;
			}
		}
		curr_cmd = curr_cmd->next;
	}
	return (SUCCESS);
}

static void	ft_exec_solo_cmd(t_shell *shell, t_cmd *cmd)
{
	if (cmd->has_redir_err == true)
	{
		shell->exit_status = 1;
		return ;
	}
	signal(SIGINT, ft_signal_handler_for_parent);
	ft_setup_cmd_redirs(shell, cmd);
	if (cmd->builtin == true)
		ft_exec_builtin(shell, cmd, cmd->args[0]);
	else
		ft_exec_sys_solo_cmd(shell, cmd);
	ft_setup_signals();
	ft_restore_orig_fds(shell);
	return ;
}

static int	ft_exec_multi_cmds(t_shell *shell, t_cmd *cmd)
{
	t_cmd	*curr_cmd;
	pid_t	pid;
	int		status;
	int		child_count;

	child_count = 0;
	curr_cmd = cmd;
	while (curr_cmd)
	{
		pid = fork();
		if (pid < 0)
			return (ft_putstr_fd("fork failed", 2),
				ft_close_all_pipes(shell), FAILURE);
		if (pid > 0)
			shell->last_pid = pid;
		if (pid == 0)
			ft_exec_child_multi(shell, curr_cmd);
		else
			child_count++;
		curr_cmd = curr_cmd->next;
	}
	ft_close_all_pipes(shell);
	ft_wait_for_childs(shell, &status, child_count);
	ft_cleanup_pipes_array(shell);
	return (ft_setup_signals(), SUCCESS);
}

static void	ft_exec_child_multi(t_shell *shell, t_cmd *curr_cmd)
{
	ft_reset_signals();
	signal(SIGPIPE, SIG_IGN);
	ft_handle_cat(shell);
	if (curr_cmd->has_redir_err == true)
		exit(1);
	ft_setup_cmd_redirs(shell, curr_cmd);
	ft_close_unused_child_pipes(shell, curr_cmd->index);
	if (curr_cmd->builtin == true)
		ft_exec_builtin(shell, curr_cmd, curr_cmd->args[0]);
	else
		ft_exec_multi_sys_cmd(shell, curr_cmd);
	ft_child_cleanup_fds_only(shell);
	exit(shell->exit_status);
	return ;
}
