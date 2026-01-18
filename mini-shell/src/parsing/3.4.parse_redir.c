/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.4.parse_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:18:25 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/05 12:54:39 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_redir_len(char *str)
{
	int		len;
	char	*copy;

	len = 1;
	copy = blackout_quoted_content(str);
	if (!copy)
		return (ft_putstr_fd("blackout_quoted_content", 2), -1);
	if (copy[len] == copy[len - 1])
		len++;
	while (is_whitespace(copy[len]))
		len++;
	while (copy[len] && (is_quote(copy[len]) || is_other(copy[len])))
		len++;
	free (copy);
	return (len);
}

void	fill_redirs_arr(char *redirect, t_cmd *cmd)
{
	static int	i;

	cmd->redirs->list[i] = redirect;
	i++;
	if (i == cmd->redirs_count)
	{
		cmd->redirs->list[i] = NULL;
		i = 0;
	}
}

int	parse_redir(char *cmd_str, t_cmd *cmd)
{
	int		index;
	char	*redirect;

	index = get_redir_len(cmd_str);
	if (index > 0)
	{
		redirect = ft_substr(cmd_str, 0, index);
		if (!redirect)
			return (-1);
		fill_redirs_arr(redirect, cmd);
	}
	return (index);
}
