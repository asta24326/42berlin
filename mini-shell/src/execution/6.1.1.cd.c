/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.1.1.cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:28:23 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/02 23:14:00 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_handle_cd_err(char *msg, char *path, int use_perror);
static int	ft_validate_and_get_target(t_cmd *cmd, char **target);
static char	*ft_get_target(t_cmd *cmd);

int	ft_cd(t_shell *shell, t_cmd *cmd)
{
	char	new_pwd[PATH_MAX];
	char	old_pwd[PATH_MAX];
	char	*target;

	if (getcwd(old_pwd, PATH_MAX) == NULL)
		return (perror("minishell: cd"), FAILURE);
	if (ft_validate_and_get_target(cmd, &target) == FAILURE)
		return (FAILURE);
	if (chdir(target) == -1)
		return (ft_handle_cd_err("", target, 1));
	if (getcwd(new_pwd, PATH_MAX) == NULL)
		return (perror("minishell: cd"), FAILURE);
	ft_set_cd_vars(shell, "PWD", new_pwd);
	ft_set_cd_vars(shell, "OLDPWD", old_pwd);
	if (cmd->args[1] && ft_strcmp(cmd->args[1], "-") == 0)
		printf("%s\n", new_pwd);
	return (SUCCESS);
}

static int	ft_handle_cd_err(char *msg, char *path, int use_perror)
{
	ft_putstr_fd("minishell: cd: ", 2);
	if (path)
	{
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
	}
	if (use_perror)
		perror(msg);
	else
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	return (FAILURE);
}

static int	ft_validate_and_get_target(t_cmd *cmd, char **target)
{
	if (cmd->args_count > 2)
		return (ft_handle_cd_err("too many arguments", NULL, 0));
	*target = ft_get_target(cmd);
	if (!*target)
		return (ft_handle_cd_err("HOME/OLDPWD not set", NULL, 0));
	return (SUCCESS);
}

static char	*ft_get_target(t_cmd *cmd)
{
	char	*target;

	if (!cmd->args[1] || ft_strcmp(cmd->args[1], "~") == 0)
		target = getenv("HOME");
	else if (ft_strcmp(cmd->args[1], "-") == 0)
		target = getenv("OLDPWD");
	else
		target = cmd->args[1];
	return (target);
}
