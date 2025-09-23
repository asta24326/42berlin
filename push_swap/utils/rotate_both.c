/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:23:51 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/09/20 21:25:55 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rr(a, b, true);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rrr(a, b, true);
	current_index(*a);
	current_index(*b);
}
