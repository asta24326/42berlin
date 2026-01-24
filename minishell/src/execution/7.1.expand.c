/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.1.expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:27:14 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/08 16:29:29 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_expand(t_shell *shell)
{
	t_cmd	*curr_cmd;

	curr_cmd = shell->cmd;
	while (curr_cmd)
	{
		if (ft_expand_redirs_list(shell, curr_cmd) == FAILURE)
			return (FAILURE);
		if (ft_expand_args_list(shell, curr_cmd) == FAILURE)
			return (FAILURE);
		curr_cmd = curr_cmd->next;
	}
	return (SUCCESS);
}

int	ft_expand_redirs_list(t_shell *shell, t_cmd *cmd)
{
	int		i;
	char	*expanded;

	if (cmd->redirs && cmd->redirs->list)
	{
		i = -1;
		while (cmd->redirs->list[++i])
		{
			if (ft_strchr(cmd->redirs->list[i], '$') != NULL)
			{
				shell->expansion = prepare_expasion();
				expanded = ft_expand_str(shell, cmd->redirs->list[i]);
				if (!expanded)
					return (free(shell->expansion), FAILURE);
				free(cmd->redirs->list[i]);
				cmd->redirs->list[i] = expanded;
				free(shell->expansion);
			}
		}
	}
	return (SUCCESS);
}

int	ft_expand_args_list(t_shell *shell, t_cmd *cmd)
{
	int		i;
	char	*expanded;

	i = -1;
	while (cmd->args[++i])
	{
		if (ft_strchr(cmd->args[i], '$') != NULL)
		{
			shell->expansion = prepare_expasion();
			expanded = ft_expand_str(shell, cmd->args[i]);
			free(cmd->args[i]);
			if (!expanded)
				return (free(shell->expansion), FAILURE);
			cmd->args[i] = expanded;
			free(shell->expansion);
		}
	}
	return (SUCCESS);
}

char	*ft_expand_str(t_shell *shell, char *str)
{
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (len > 1 && is_other(str[0]))
		return (ft_expand_simple_str(shell, str));
	if (len > 1 && str[0] == '\'' && str[len - 1] == '\'')
		return (ft_strdup(str));
	if (len > 1 && str[0] == '"' && str[len - 1] == '"')
		return (ft_expand_dquotes_str(shell, str));
	return (ft_strdup(str));
}

char	*ft_expand_dollar_start(t_shell *shell, char *str)
{
	char	*exit_str;
	char	*result;

	if (str[1] == '?')
	{
		exit_str = ft_itoa(shell->exit_status);
		if (str[2])
		{
			result = ft_strjoin(exit_str, &str[2]);
			return (free(exit_str), result);
		}
		return (exit_str);
	}
	if (str[1] == '$')
		return (ft_itoa(shell->shell_pid));
	if (str[1] && ft_is_valid_var_char(str[1]) == true)
		return (ft_expand_env_var(shell, str, ft_strlen(str)));
	if (str[1] == '\0' || !ft_is_valid_var_char(str[1]))
		return (ft_strdup("$"));
	return (ft_strdup(str));
}
