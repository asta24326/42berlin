/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.1.tokenize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:33:40 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/05 19:31:24 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	tokenize(char *cmd_str, t_cmd *cmd)
{
	int	index;

	index = 0;
	while (*cmd_str)
	{
		if (is_quote(*cmd_str))
			index = parse_quote(cmd_str, cmd);
		else if (is_other(*cmd_str))
			index = parse_cmd(cmd_str, cmd);
		else if (is_redir(*cmd_str))
			index = parse_redir(cmd_str, cmd);
		else
			index = 1;
		if (index == -1)
			return (FAILURE);
		cmd_str += index;
	}
	if (cmd->redirs != NULL && cmd->redirs->hdoc_count > 0)
		parse_hdoc(cmd->redirs);
	return (SUCCESS);
}
