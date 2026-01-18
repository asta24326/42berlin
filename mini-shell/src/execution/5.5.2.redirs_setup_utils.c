/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.5.2.redirs_setup_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:01:31 by asharafe          #+#    #+#             */
/*   Updated: 2026/01/04 14:56:50 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_hdoc	*ft_get_last_hdoc(t_hdoc *head)
{
	t_hdoc	*curr;

	curr = head;
	if (curr == NULL)
		return (0);
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}
