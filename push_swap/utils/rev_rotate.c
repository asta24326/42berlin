/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:03:47 by asharafe          #+#    #+#             */
/*   Updated: 2025/09/20 21:25:54 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_node **top);

void	rra(t_node	**a, bool print)
{
	rev_rotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_node	**b, bool print)
{
	rev_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (print)
		ft_printf("rrr\n");
}

static void	rev_rotate(t_node **stack)
{
	t_node	*pre_last_node;
	t_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	pre_last_node = get_prelast(*stack);
	last_node = get_last(*stack);
	pre_last_node->next = NULL;
	last_node->prev = NULL;
	last_node->next = *stack;
	(*stack)->prev = last_node;
	*stack = last_node;
}
