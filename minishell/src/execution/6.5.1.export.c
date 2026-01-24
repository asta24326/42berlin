/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.5.1.export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:29:54 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/06 13:36:37 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		ft_set_var(t_shell *shell, char *var);
static int		ft_add_new_var(t_shell *shell, char *var);
static void		ft_print_all(char **env);

int	ft_export(t_shell *shell, t_cmd *cmd)
{
	int		i;

	if (!cmd->args[1] || !cmd->args[1][0])
		return (ft_print_all(shell->env), SUCCESS);
	i = 0;
	while (cmd->args[++i])
	{
		if (ft_is_valid_var_name(cmd->args[i]) == false)
		{
			ft_putstr_fd("minishell: export: '", 2);
			ft_putstr_fd(cmd->args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (FAILURE);
		}
		if (ft_set_var(shell, cmd->args[i]) == FAILURE)
			return (ft_putstr_fd("set env var failed", 2), FAILURE);
	}
	return (SUCCESS);
}

static int	ft_set_var(t_shell *shell, char *var)
{
	int		i;
	size_t	var_len;
	char	*equals_sign;

	equals_sign = ft_strchr(var, '=');
	var_len = ft_get_var_name_len(var);
	i = -1;
	while (shell->env[++i])
	{
		if (ft_strncmp(shell->env[i], var, var_len) == 0
			&& (shell->env[i][var_len] == '='
			|| shell->env[i][var_len] == '\0'))
		{
			if (equals_sign)
			{
				free(shell->env[i]);
				shell->env[i] = ft_strdup(var);
				if (!shell->env[i])
					return (FAILURE);
			}
			return (SUCCESS);
		}
	}
	return (ft_add_new_var(shell, ft_strdup(var)));
}

static int	ft_add_new_var(t_shell *shell, char *var)
{
	char	**new_env_arr;
	int		env_len;
	int		i;

	if (!var)
		return (FAILURE);
	var = ft_normalize_env_var(var);
	if (!var)
		return (FAILURE);
	env_len = 0;
	while (shell->env[env_len])
		env_len++;
	new_env_arr = malloc(sizeof(char *) * (env_len + 2));
	if (!new_env_arr)
		return (free(var), FAILURE);
	i = -1;
	while (shell->env[++i])
		new_env_arr[i] = shell->env[i];
	new_env_arr[i] = var;
	new_env_arr[i + 1] = NULL;
	free(shell->env);
	shell->env = new_env_arr;
	return (SUCCESS);
}

static void	ft_print_all(char **env)
{
	int		i;
	char	**sorted_env;

	if (!env || !env[0])
		return ;
	sorted_env = ft_sort_env(env);
	if (!sorted_env)
		return ;
	i = -1;
	while (sorted_env[++i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_print_var_with_quotes(sorted_env[i]);
		ft_putstr_fd("\n", 1);
	}
	ft_free_arr_str(sorted_env);
}

bool	ft_is_valid_var_name(char *var)
{
	size_t	i;
	size_t	var_name_len;

	if (!var || !var[0])
		return (false);
	if (var[0] != '_' && !ft_isalpha(var[0]))
		return (false);
	var_name_len = ft_get_var_name_len(var);
	i = 0;
	while (++i < var_name_len)
		if (var[i] != '_' && !ft_isalnum(var[i]))
			return (false);
	return (true);
}
