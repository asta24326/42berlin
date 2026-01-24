/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.5.2.export_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:48:00 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/12/28 13:30:46 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_sort_algo(int count, char **sorted);

char	**ft_sort_env(char **env)
{
	char	**sorted;
	int		count;
	int		i;

	count = 0;
	while (env[count])
		count++;
	sorted = malloc(sizeof(char *) * (count + 1));
	if (!sorted)
		return (NULL);
	i = -1;
	while (env[++i])
	{
		sorted[i] = ft_strdup(env[i]);
		if (!sorted[i])
		{
			while (--i >= 0)
				free(sorted[i]);
			free(sorted);
			return (NULL);
		}
	}
	sorted[count] = NULL;
	ft_sort_algo(count, sorted);
	return (sorted);
}

static void	ft_sort_algo(int count, char **sorted)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	while (++i < count - 1)
	{
		j = i;
		while (++j < count)
		{
			if (ft_strcmp(sorted[i], sorted[j]) > 0)
			{
				temp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = temp;
			}
		}
	}
}

char	*ft_normalize_env_var(char *var)
{
	char	*result;

	if (ft_strchr(var, '='))
		return (var);
	result = ft_strjoin(var, "=");
	if (!result)
		return (ft_putstr_fd("malloc failed", 2), NULL);
	free(var);
	return (result);
}

void	ft_print_var_with_quotes(char *var)
{
	char	*equals_pos;

	equals_pos = ft_strchr(var, '=');
	if (equals_pos)
	{
		write(1, var, equals_pos - var);
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(equals_pos + 1, 1);
		ft_putstr_fd("\"", 1);
	}
	else
		ft_putstr_fd(var, 1);
}
