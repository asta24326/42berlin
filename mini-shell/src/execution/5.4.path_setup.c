/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.4.path_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 23:05:41 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/01/06 14:20:33 by asharafe         ###   ########.fr       */
/*   Updated: 2026/01/06 14:18:50 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_getpath(char *cmd, char **env)
{
	char	**allpaths;
	char	*path_prep;
	char	*exec_str;
	int		i;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	allpaths = ft_split(ft_parse_env("PATH", env), ':');
	if (!allpaths)
		return (NULL);
	i = -1;
	while (allpaths[++i])
	{
		path_prep = ft_strjoin(allpaths[i], "/");
		exec_str = ft_strjoin(path_prep, cmd);
		free (path_prep);
		if (access(exec_str, F_OK | X_OK) == 0)
			return (ft_free_arr_str(allpaths), exec_str);
		free (exec_str);
	}
	return (ft_free_arr_str(allpaths), NULL);
}

char	*ft_parse_env(char *name, char **env)
{
	int		i;
	int		j;
	char	*substr;

	if (!name || !env)
		return (NULL);
	i = -1;
	while (env[++i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		substr = ft_substr(env[i], 0, j);
		if (!substr)
			return (NULL);
		if ((ft_strcmp(substr, name)) == 0)
		{
			free(substr);
			return (&env[i][j + 1]);
		}
		free(substr);
	}
	return (NULL);
}

void	ft_free_arr_str(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}
