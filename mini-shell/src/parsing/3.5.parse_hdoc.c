/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.5.parse_hdoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:59:04 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/05 12:49:06 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_delimiter(char *cmd_str)
{
	int	skip;
	int	len;

	skip = 0;
	len = ft_strlen(cmd_str);
	while (is_redir(cmd_str[skip]) || is_whitespace(cmd_str[skip]))
		skip += 1;
	return (ft_substr(cmd_str, skip, len - skip));
}

void	parse_hdoc(t_redirs *redirs)
{
	char	**list;
	t_hdoc	*head;
	int		i;

	list = redirs->list;
	head = redirs->hdocs;
	i = -1;
	while (list[++i])
	{
		if (list[i][0] == '<' && list[i][1] == '<')
		{
			redirs->hdocs->hdoc_delim = get_delimiter(list[i]);
			if (redirs->hdocs->next != NULL)
				redirs->hdocs = redirs->hdocs->next;
		}
	}
	redirs->hdocs = head;
}
