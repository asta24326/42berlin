/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10.1.3.cleanup_hdocs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 12:28:07 by asharafe          #+#    #+#             */
/*   Updated: 2026/01/04 12:29:56 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_cleanup_hdocs_list(t_hdoc **hdocs_list)
{
	t_hdoc	*current;
	t_hdoc	*next;

	if (!hdocs_list || !*hdocs_list)
		return ;
	current = *hdocs_list;
	while (current)
	{
		next = current->next;
		ft_cleanup_hdoc(current);
		current = next;
	}
	*hdocs_list = NULL;
}

void	ft_cleanup_hdoc(t_hdoc *hdoc)
{
	if (!hdoc)
		return ;
	free(hdoc->hdoc_delim);
	if (hdoc->hdoc_fd[0] >= 0)
	{
		close(hdoc->hdoc_fd[0]);
		hdoc->hdoc_fd[0] = -1;
	}
	if (hdoc->hdoc_fd[1] >= 0)
	{
		close(hdoc->hdoc_fd[1]);
		hdoc->hdoc_fd[1] = -1;
	}
	free(hdoc);
}
