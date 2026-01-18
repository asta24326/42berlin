/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.1.2.cd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:12:27 by asharafe          #+#    #+#             */
/*   Updated: 2025/12/29 16:15:56 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*ft_strjoin_three(char *key, char *value);
static int	ft_create_cd_arg(t_shell *shell, char *new_var);

int	ft_set_cd_vars(t_shell *shell, char *key, char *value)
{
	char	*new_var;
	int		i;

	new_var = ft_strjoin_three(key, value);
	i = 0;
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], key, ft_strlen(key)) == 0
			&& shell->env[i][ft_strlen(key)] == '=')
		{
			free(shell->env[i]);
			shell->env[i] = new_var;
			return (SUCCESS);
		}
		i++;
	}
	if (ft_create_cd_arg(shell, new_var) == FAILURE)
		return (free(new_var), FAILURE);
	return (SUCCESS);
}

static char	*ft_strjoin_three(char *key, char *value)
{
	char	*temp;
	char	*res;

	temp = ft_strjoin(key, "=");
	if (!temp)
		return (ft_putstr_fd("cd: env update failed", 2), NULL);
	res = ft_strjoin(temp, value);
	if (!res)
		return (ft_putstr_fd("cd: env update failed", 2), NULL);
	free(temp);
	return (res);
}

static int	ft_create_cd_arg(t_shell *shell, char *new_var)
{
	char	**new_env;
	int		env_len;
	int		i;

	env_len = 0;
	while (shell->env[env_len])
		env_len++;
	new_env = malloc(sizeof(char *) * (env_len + 2));
	if (!new_env)
		return (FAILURE);
	i = -1;
	while (shell->env[++i])
		new_env[i] = shell->env[i];
	new_env[i] = new_var;
	new_env[i + 1] = NULL;
	free(shell->env);
	shell->env = new_env;
	return (SUCCESS);
}
