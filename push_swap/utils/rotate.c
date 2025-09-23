/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:02:49 by asharafe          #+#    #+#             */
/*   Updated: 2025/09/20 21:25:56 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **top);

void	ra(t_node	**a, bool print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_node	**b, bool print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
}

static void	rotate(t_node **top)
{
	t_node	*last_node;

	if (!*top || !(*top)->next)
		return ;
	last_node = get_last(*top);
	last_node->next = *top;
	*top = (*top)->next;
	(*top)->prev = NULL;
	last_node->next->prev = last_node;
	last_node ->next->next = NULL;
}
