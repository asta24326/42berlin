/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12.1.shell_lvl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:35:28 by asharafe          #+#    #+#             */
/*   Updated: 2026/01/06 14:30:17 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_setup_shlvl(t_shell *shell)
{
	char	*shlvl_str;
	int		shlvl;
	char	*new_shlvl;
	int		i;

	shlvl_str = ft_getenv(shell->env, "SHLVL");
	if (!shlvl_str)
		shlvl = 1;
	else
		shlvl = ft_atoi(shlvl_str);
	if (shlvl < 0)
		shlvl = 1;
	else
		shlvl++;
	new_shlvl = ft_itoa(shlvl);
	i = -1;
	while (shell->env[++i])
		if (!ft_strncmp(shell->env[i], "SHLVL=", 6))
			break ;
	if (shell->env[i])
		(free(shell->env[i]), shell->env[i] = ft_strjoin("SHLVL=", new_shlvl));
	else
		shell->env = ft_add_str_arr(shell->env,
				ft_strjoin("SHLVL=", new_shlvl));
	free(new_shlvl);
}

char	**ft_add_str_arr(char **arr, char *str)
{
	char	**new;
	int		i;
	int		len;

	len = 0;
	while (arr && arr[len])
		len++;
	new = malloc(sizeof(char *) * (len + 2));
	if (!new)
		return (free(str), NULL);
	i = -1;
	while (++i < len)
		new[i] = ft_strdup(arr[i]);
	new[i] = str;
	new[i + 1] = NULL;
	ft_free_arr_str(arr);
	return (new);
}
