/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.2.prepare_cmd_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:40:26 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/05 12:45:58 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*create_node(char *cmd_line)
{
	t_cmd	*new;
	char	*copy;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (ft_putstr_fd("create_node, t_cmd", 2), NULL);
	copy = blackout_quoted_content(cmd_line);
	if (!copy)
		return (ft_putstr_fd("create_node, copy", 2), free(new), NULL);
	if (prepare_args_arr(copy, new))
		return (free(new), free(copy), NULL);
	new->builtin = NULL;
	if (new->redirs_count > 0)
	{
		if (prepare_redirs(cmd_line, new))
			return (free(new), free(copy), NULL);
	}
	else
		new->redirs = NULL;
	new->skip_in_pipe = false;
	new->skip_out_pipe = false;
	new->has_redir_err = false;
	new->next = NULL;
	return (free(copy), new);
}

void	add_node(t_cmd **list, t_cmd *new)
{
	t_cmd	*head;

	head = *list;
	while (head != NULL && head->next != NULL)
		head = head->next;
	head->next = new;
}

void	set_index(t_cmd *stack, int cmd_count)
{
	int		i;
	t_cmd	*current;

	i = -1;
	current = stack;
	while (++i < cmd_count)
	{
		current->index = i;
		current = current->next;
	}
}

void	create_cmd_list(char **arr, int cmd_count, t_shell *minishell)
{
	t_cmd	*list;
	int		i;

	list = create_node(arr[0]);
	i = 0;
	while (++i < cmd_count)
		add_node(&list, create_node(arr[i]));
	set_index(list, cmd_count);
	minishell->cmd = list;
}
