/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10.1.2.cleanup_after_cmd_exec.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:09:43 by asharafe          #+#    #+#             */
/*   Updated: 2025/12/28 12:36:45 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_cleanup_after_cmd_exec(t_shell *shell)
{
	if (!shell)
		return ;
	ft_close_all_pipes(shell);
	ft_cleanup_pipes_array(shell);
	ft_cleanup_cmd_list(&shell->cmd);
	ft_restore_std_fds(shell);
}

void	ft_restore_std_fds(t_shell *shell)
{
	if (shell->orig_stdin >= 0)
	{
		dup2(shell->orig_stdin, STDIN_FILENO);
		close(shell->orig_stdin);
		shell->orig_stdin = -1;
	}
	if (shell->orig_stdout >= 0)
	{
		dup2(shell->orig_stdout, STDOUT_FILENO);
		close(shell->orig_stdout);
		shell->orig_stdout = -1;
	}
}

void	ft_child_cleanup_fds_only(t_shell *shell)
{
	if (shell->orig_stdin >= 0)
		close(shell->orig_stdin);
	if (shell->orig_stdout >= 0)
		close(shell->orig_stdout);
	ft_close_all_pipes(shell);
}
