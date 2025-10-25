/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 22:26:24 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/09/21 13:13:48 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_a_to_b(t_node **a, t_node **b);
static void	move_b_to_a(t_node **a, t_node **b);
static void	min_on_top(t_node **a);

void	sort_stacks(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, true);
	// if (len_a-- > 3 && !stack_sorted(*a))
	// 	pb(b, a, true);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

void	prep_for_push(t_node **stack, t_node *cheapest_node, char stack_name)
{
	while (*stack != cheapest_node)
	{
		if (stack_name == 'a')
		{
			if (cheapest_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		if (stack_name == 'b')
		{
			if (cheapest_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

static void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, true);
}

static void	move_b_to_a(t_node **a, t_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

static void	min_on_top(t_node **a)
{
	t_node	*min_node;

	min_node = get_min(*a);
	while (*a != min_node)
	{
		if (min_node->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}
