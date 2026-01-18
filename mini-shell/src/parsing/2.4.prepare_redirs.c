/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.4.prepare_redirs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:56:50 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/05 12:46:32 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_hdoc_count(char *copy)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (copy[++i])
		if (copy[i] == '<' && copy[i + 1] == '<')
			count += 1;
	return (count);
}

int	prepare_redirs(char *copy, t_cmd *cmd)
{
	t_redirs	*redirects;

	redirects = (t_redirs *)malloc(sizeof(t_redirs));
	if (!redirects)
		return (ft_putstr_fd("prepare_redirs, struct", 2), FAILURE);
	redirects->list = ft_calloc(cmd->redirs_count + 1, sizeof(char *));
	if (!redirects->list)
	{
		ft_putstr_fd("prepare_redirs, list", 2);
		return (free(redirects), FAILURE);
	}
	redirects->in_fd = -1;
	redirects->out_fd = -1;
	redirects->hdoc_count = get_hdoc_count(copy);
	if (redirects->hdoc_count > 0)
		prepare_hdoc_list(redirects);
	else
		redirects->hdocs = NULL;
	cmd->redirs = redirects;
	return (SUCCESS);
}
