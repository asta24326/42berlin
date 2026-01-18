/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8.1.env_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:39:10 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/12/28 13:31:16 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_env_dup(char **env)
{
	char	**new_env;
	int		i;
	int		count;

	count = -1;
	while (env[++count])
		;
	new_env = malloc(sizeof(char *) * (count + 1));
	if (!new_env)
		return (ft_putstr_fd("env_init malloc failed", 2), NULL);
	i = -1;
	while (++i < count)
	{
		new_env[i] = ft_strdup(env[i]);
		if (!new_env[i])
		{
			while (--i >= 0)
				free(new_env[i]);
			free(new_env);
			return (NULL);
		}
	}
	new_env[count] = NULL;
	return (new_env);
}
