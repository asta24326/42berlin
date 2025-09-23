/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:19:35 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/09/20 21:25:59 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_node *stack)
{
	if (!stack)
		return (false);
	while (stack->next)
	{
		if ((stack->nbr) > (stack->next->nbr))
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	stack_len(t_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

// void	print_content(const t_node *stack)
// {
// 	while (stack->next != NULL)
// 	{
// 		ft_printf("%d\n", stack->nbr);
// 		stack = stack->next;
// 	}
// }
