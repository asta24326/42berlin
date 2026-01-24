/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.3.2.exec_sys_cmd_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:01:40 by asharafe          #+#    #+#             */
/*   Updated: 2026/01/06 14:30:13 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_is_cmd_is_dir(t_shell *shell, char *arg)
{
	DIR	*dir;

	if (ft_strchr(arg, '/') != NULL)
	{
		dir = opendir(arg);
		if (dir)
		{
			closedir(dir);
			ft_err_msg(shell, arg, "Is a directory\n", 126);
			return (true);
		}
		if (access(arg, F_OK) != 0)
		{
			ft_err_msg(shell, arg, "No such file or directory\n", 127);
			return (true);
		}
		if (access(arg, X_OK) != 0)
		{
			ft_err_msg(shell, arg, "Permission denied\n", 126);
			return (true);
		}
		return (false);
	}
	return (false);
}

void	ft_err_msg(t_shell *shell, char *cmd, char *msg, int code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	shell->exit_status = code;
}
