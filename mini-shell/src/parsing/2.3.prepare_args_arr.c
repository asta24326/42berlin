/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.3.prepare_args_arr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:37:46 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/05 12:46:19 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_redir_count(char *copy)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (copy[i])
	{
		if (is_redir(copy[i]))
		{
			count++;
			i++;
			if (is_redir(copy[i]))
				i++;
		}
		else
			i++;
	}
	return (count);
}

int	get_arg_count(char *copy, int redirs_count)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (copy[i])
	{
		if (!is_whitespace(copy[i]) && !is_redir(copy[i]))
		{
			count++;
			while (copy[i] && !is_whitespace(copy[i])
				&& !is_redir(copy[i]))
				i++;
		}
		else
			i++;
	}
	return (count - redirs_count);
}

int	prepare_args_arr(char *copy, t_cmd *cmd)
{
	cmd->redirs_count = get_redir_count(copy);
	cmd->args_count = get_arg_count(copy, cmd->redirs_count);
	cmd->args = ft_calloc(cmd->args_count + 1, sizeof(char *));
	if (!cmd->args)
		return (ft_putstr_fd("prepare_args_arr", 2), FAILURE);
	return (SUCCESS);
}
