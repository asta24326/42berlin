/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:15:59 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/09/20 21:25:57 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	ft_sort_three(t_node **a)
{
	t_node	*biggest;
	t_node	*smallest;

	if (((*a)->nbr < (*a)->next->nbr)
		&& ((*a)->next->nbr < (*a)->next->next->nbr))
		return ;
	biggest = get_max(*a);
	smallest = get_min(*a);
	if ((*a) == smallest)
		if ((*a)->next == biggest)
			return (rra(a, false), sa(a, false));
	else if ((*a) == biggest)
	{
		if ((*a)->next == smallest)
			return (ra(a, false));
		return (sa(a, false), rra(a, false));
	}
	else
	{
		if ((*a)->next == biggest)
			rra(a, false);
		if ((*a)->next == smallest)
			sa(a, false);
	}
	return ;
}
*/

void	sort_three(t_node **a)
{
	t_node	*biggest_node;

	biggest_node = get_max(*a);
	if (*a == biggest_node)
		ra(a, true);
	else if ((*a)->next == biggest_node)
		rra(a, true);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, true);
}
