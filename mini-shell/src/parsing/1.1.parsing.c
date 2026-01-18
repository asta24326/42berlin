/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.1.parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:29:02 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/08 13:18:43 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*blackout_quoted_content(char *str)
{
	char	*copy;
	char	quot_mark;
	int		i;

	copy = ft_strjoin("", str);
	quot_mark = 0;
	i = -1;
	while (copy[++i])
	{
		if (is_quote(copy[i]))
		{
			quot_mark = copy[i];
			i++;
			while (copy[i + 1] && copy[i] != quot_mark)
			{
				copy[i] = 48;
				i++;
			}
		}
	}
	return (copy);
}

int	parse(char *pipeline, t_shell *minishell)
{
	char	*copy;

	ft_cleanup_cmd_list(&minishell->cmd);
	copy = blackout_quoted_content(pipeline);
	if (!copy)
		return (ft_putstr_fd("blackout_quoted_content", 2), FAILURE);
	minishell->pipe_count = get_pipe_count(copy);
	if (is_valid_syntax(copy, minishell->pipe_count) == false)
	{
		minishell->exit_status = 2;
		return (free(copy), FAILURE);
	}
	if (parse_cmd_lines(copy, pipeline, minishell->pipe_count + 1, minishell))
	{
		ft_cleanup_cmd_list(&minishell->cmd);
		minishell->pipe_count = 0;
		return (free(copy), FAILURE);
	}
	return (free(copy), SUCCESS);
}

t_exp	*prepare_expasion(void)
{
	t_exp	*new;

	new = (t_exp *)malloc(sizeof(t_exp));
	if (!new)
		return (ft_putstr_fd("malloc failed", 2), NULL);
	new->temp = NULL;
	new->temp2 = NULL;
	new->last_opt = 0;
	return (new);
}
