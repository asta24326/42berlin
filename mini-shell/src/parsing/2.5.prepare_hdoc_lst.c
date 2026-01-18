/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.5.prepare_hdoc_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:32:16 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/05 12:46:45 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_hdoc	*create_hdoc_node(int index)
{
	t_hdoc	*new;

	new = (t_hdoc *)malloc(sizeof(t_hdoc));
	if (!new)
		return (ft_putstr_fd("prepare_hdoc_list, t_hdoc", 2), NULL);
	new->index = index;
	new->hdoc_delim = NULL;
	new->hdoc_fd[0] = -1;
	new->hdoc_fd[1] = -1;
	new->next = NULL;
	return (new);
}

void	add_hdoc_node(t_hdoc **list, t_hdoc *new)
{
	t_hdoc	*head;

	head = *list;
	while (head != NULL && head->next != NULL)
		head = head->next;
	head->next = new;
}

void	prepare_hdoc_list(t_redirs *redirects)
{
	int		index;
	t_hdoc	*list;

	index = 0;
	list = create_hdoc_node(index);
	while (++index < redirects->hdoc_count)
		add_hdoc_node(&list, create_hdoc_node(index));
	redirects->hdocs = list;
}
