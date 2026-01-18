/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.6.exec_multi_sys_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:26:48 by asharafe          #+#    #+#             */
/*   Updated: 2026/01/02 23:10:16 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_error(t_shell *shell, char *cmd, char *msg, int exit_code);

int	ft_exec_multi_sys_cmd(t_shell *shell, t_cmd *cmd)
{
	char	*path;

	if (ft_is_cmd_is_dir(shell, cmd->args[0]) == true)
		return (FAILURE);
	path = ft_getpath(cmd->args[0], shell->env);
	if (!path)
		return (ft_error(shell, cmd->args[0],
				"command not found", 127), 127);
	if (access(path, F_OK) != 0)
		return (ft_error(shell, cmd->args[0],
				"No such file or directory", 127), free(path), 127);
	if (access(path, X_OK) != 0)
		return (ft_error(shell, cmd->args[0], "Permission denied", 126),
			free(path), 126);
	signal(SIGPIPE, SIG_IGN);
	if (execve(path, cmd->args, shell->env) == -1)
		return (ft_putstr_fd("execve failed\n", 2), free(path),
			ft_child_cleanup_fds_only(shell), exit(1), 1);
	free(path);
	return (SUCCESS);
}

int	ft_isdir(char *path)
{
	DIR	*dir;

	dir = opendir(path);
	if (dir)
	{
		closedir(dir);
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	ft_error(t_shell *shell, char *cmd, char *msg, int exit_code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	ft_child_cleanup_fds_only(shell);
	shell->exit_status = exit_code;
	exit(exit_code);
}
