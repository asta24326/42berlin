/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11.1.2.pipes_handle_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 01:03:34 by asharafe          #+#    #+#             */
/*   Updated: 2026/01/02 23:11:06 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_adjust_pipes_for_skipped_cmds(t_shell *shell)
{
	t_cmd	*curr;

	curr = shell->cmd;
	while (curr)
	{
		if (curr->has_redir_err == true)
		{
			if (curr->index > 0)
			{
				close(shell->pipes[curr->index - 1][0]);
				shell->pipes[curr->index - 1][0] = -1;
			}
			if (curr->index < shell->pipe_count)
			{
				close(shell->pipes[curr->index][1]);
				shell->pipes[curr->index][1] = -1;
			}
		}
		curr = curr->next;
	}
}
