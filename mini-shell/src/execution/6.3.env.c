/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.3.env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:57:12 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/12/26 20:52:58 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env(t_shell *shell, t_cmd *cmd)
{
	int	i;

	(void)cmd;
	if (!shell->env)
		return (FAILURE);
	i = -1;
	while (shell->env[++i])
	{
		if (ft_strchr(shell->env[i], '='))
		{
			ft_putstr_fd(shell->env[i], 1);
			ft_putstr_fd("\n", 1);
		}
	}
	return (SUCCESS);
}

char	*ft_getenv(char **env, char *var_name)
{
	int		i;
	size_t	name_len;

	if (!env || !var_name)
		return (NULL);
	name_len = ft_strlen(var_name);
	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], var_name, name_len) == 0)
		{
			if (env[i][name_len] == '=')
				return (&env[i][name_len + 1]);
		}
	}
	return (NULL);
}
