/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.1.parse_cmd_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:33:41 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/06 15:39:20 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	process_cmd(t_shell *minishell, char *cmd_str)
{
	if (tokenize(cmd_str, minishell->cmd))
	{
		ft_putstr_fd("tokenize failed\n", 2);
		return (FAILURE);
	}
	ft_process_all_heredocs(minishell);
	if (ft_expand(minishell) == FAILURE)
	{
		minishell->exit_status = FAILURE;
		ft_cleanup_pipes_array(minishell);
		return (FAILURE);
	}
	if (cleanup_quotes(minishell->cmd->args))
		return (FAILURE);
	if (is_builtin_cmd(minishell->cmd))
		minishell->cmd->builtin = true;
	else
		minishell->cmd->builtin = false;
	if (minishell->cmd->redirs_count > 0)
	{
		if (cleanup_quotes(minishell->cmd->redirs->list))
			return (FAILURE);
	}
	return (SUCCESS);
}

char	**split_pipeline(char *copy, char *pipeline, t_shell *minishell)
{
	char	**arr_copy;
	char	**arr_final;
	int		i;
	int		j;

	arr_copy = ft_split(copy, '|');
	if (!arr_copy)
		return (NULL);
	arr_final = ft_calloc(minishell->pipe_count + 2, sizeof(char *));
	i = -1;
	j = 0;
	while (arr_copy[++i])
	{
		j = ft_strlen(arr_copy[i]);
		arr_final[i] = ft_calloc(j + 1, sizeof(char));
		ft_strlcat(arr_final[i], pipeline, j + 1);
		pipeline += j + 1;
	}
	arr_final[i] = NULL;
	return (ft_free_arr(arr_copy), arr_final);
}

int	parse_cmd_lines(char *copy, char *pline, int cmd_count, t_shell *minishell)
{
	char	**arr;
	t_cmd	*head;
	int		i;

	arr = split_pipeline(copy, pline, minishell);
	if (!arr)
		return (ft_putstr_fd("split failed\n", 2), FAILURE);
	create_cmd_list(arr, cmd_count, minishell);
	head = minishell->cmd;
	i = -1;
	while (++i < cmd_count)
	{
		if (process_cmd(minishell, arr[i]) == FAILURE)
		{
			ft_putstr_fd("ft_process_cmd failed\n", 2);
			return (ft_free_arr(arr), FAILURE);
		}
		minishell->cmd = minishell->cmd->next;
	}
	minishell->cmd = head;
	return (ft_free_arr(arr), SUCCESS);
}
