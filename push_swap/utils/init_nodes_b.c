/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 23:47:35 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/09/20 21:25:52 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_node *a, t_node *b);

void	init_nodes_b(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

static void	set_target_b(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target_node;
	long	best_match_value;

	while (b)
	{
		best_match_value = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if ((current_a->nbr > b->nbr) && current_a->nbr < best_match_value)
			{
				best_match_value = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_value == LONG_MAX)
			b->target_node = get_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}
