/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10.1.1.cleanup_and_exit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:55:22 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/05 19:37:42 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_cleanup_and_exit(t_shell *shell, int exit_code)
{
	if (shell)
	{
		ft_cleanup_shell(shell);
		free(shell);
	}
	exit(exit_code);
}

void	ft_cleanup_shell(t_shell *shell)
{
	if (!shell)
		return ;
	ft_cleanup_cmd_list(&shell->cmd);
	ft_cleanup_pipes_array(shell);
	if (shell->prompt)
	{
		free(shell->prompt);
		shell->prompt = NULL;
	}
	if (shell->env)
	{
		ft_free_arr_str(shell->env);
		shell->env = NULL;
	}
}

void	ft_cleanup_cmd_list(t_cmd **cmd_list)
{
	t_cmd	*current;
	t_cmd	*next;

	if (!cmd_list || !*cmd_list)
		return ;
	current = *cmd_list;
	while (current)
	{
		next = current->next;
		ft_cleanup_cmd(current);
		current = next;
	}
	*cmd_list = NULL;
}

void	ft_cleanup_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	if (cmd->args)
	{
		ft_free_arr_str(cmd->args);
		cmd->args = NULL;
	}
	if (cmd->redirs)
	{
		ft_cleanup_reset_redirs(cmd->redirs);
		cmd->redirs = NULL;
	}
	free(cmd);
}

void	ft_cleanup_reset_redirs(t_redirs *redirs)
{
	if (!redirs)
		return ;
	if (redirs->in_fd > 2)
	{
		close(redirs->in_fd);
		redirs->in_fd = -1;
	}
	if (redirs->out_fd > 2)
	{
		close(redirs->out_fd);
		redirs->out_fd = -1;
	}
	if (redirs->list)
		ft_free_arr_str(redirs->list);
	if (redirs->hdocs)
		ft_cleanup_hdocs_list(&redirs->hdocs);
	free(redirs);
}
