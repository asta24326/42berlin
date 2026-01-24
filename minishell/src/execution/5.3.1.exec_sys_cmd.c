/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.3.1.exec_sys_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 23:03:19 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/06 14:29:25 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_exec_child_solo_process(t_shell *shell, t_cmd *cmd, char *path);

int	ft_exec_sys_solo_cmd(t_shell *shell, t_cmd *cmd)
{
	char	*path;
	pid_t	pid;
	int		status;

	if (!cmd || !cmd->args[0] || cmd->args[0][0] == '\0')
		return (shell->exit_status = 0, SUCCESS);
	if (ft_strchr(cmd->args[0], '/') && ft_is_cmd_is_dir(shell, cmd->args[0]))
		return (FAILURE);
	path = ft_getpath(cmd->args[0], shell->env);
	if (!path)
		return (ft_err(shell, cmd->args[0]), FAILURE);
	pid = fork();
	if (pid < 0)
		return (free(path), ft_putstr_fd("fork failed\n", 2), FAILURE);
	if (pid == 0)
		ft_exec_child_solo_process(shell, cmd, path);
	waitpid(pid, &status, 0);
	ft_handle_child_status(shell, status);
	free(path);
	return (SUCCESS);
}

static void	ft_exec_child_solo_process(t_shell *shell, t_cmd *cmd, char *path)
{
	ft_reset_signals();
	execve(path, cmd->args, shell->env);
	ft_exec_err(cmd->args[0], path);
}

int	ft_err(t_shell *shell, char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	if (ft_strchr(cmd, '/') && access(cmd, F_OK) != 0)
		ft_putstr_fd(": No such file or directory\n", 2);
	else if (ft_strchr(cmd, '/') && access(cmd, X_OK) != 0)
		ft_putstr_fd(": Permission denied\n", 2);
	else
		ft_putstr_fd(": command not found\n", 2);
	if (ft_strchr(cmd, '/') && access(cmd, F_OK) == 0
		&& access(cmd, X_OK) != 0)
		shell->exit_status = 126;
	else
		shell->exit_status = 127;
	return (FAILURE);
}

void	ft_err_dir(t_shell *shell, char *cmd, char *err, int code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err, 2);
	shell->exit_status = code;
	exit(code);
}

void	ft_exec_err(char *cmd, char *path)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	if (access(path, F_OK) != 0)
		ft_putstr_fd(": No such file or directory\n", 2);
	else if (access(path, X_OK) != 0)
		ft_putstr_fd(": Permission denied\n", 2);
	else
		ft_putstr_fd(" ", 2);
	free(path);
	exit(126);
}
