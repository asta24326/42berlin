/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.7.unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:41:32 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/06 13:27:47 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_remove_var(t_shell *shell, char *var);

int	ft_unset(t_shell *shell, t_cmd *cmd)
{
	int	i;

	if (!cmd->args[1])
		return (SUCCESS);
	i = 0;
	while (cmd->args[++i])
	{
		if (ft_is_valid_var_name(cmd->args[i]) == false)
		{
			ft_putstr_fd("minishell: unset: '", 2);
			ft_putstr_fd(cmd->args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (FAILURE);
		}
		else
			ft_remove_var(shell, cmd->args[i]);
	}
	return (SUCCESS);
}

static void	ft_remove_var(t_shell *shell, char *var)
{
	int		i;
	size_t	var_len;

	var_len = ft_get_var_name_len(var);
	i = -1;
	while (shell->env[++i])
	{
		if (ft_strncmp(shell->env[i], var, var_len) == 0
			&& (shell->env[i][var_len] == '='
			|| shell->env[i][var_len] == '\0'))
		{
			free(shell->env[i]);
			while (shell->env[i + 1])
			{
				shell->env[i] = shell->env[i + 1];
				i++;
			}
			shell->env[i] = NULL;
			return ;
		}
	}
}
