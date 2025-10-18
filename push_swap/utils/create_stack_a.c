/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:49:56 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/10/18 19:19:38 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_node(t_node **stack, int n, char **arr);

void	create_stack_a(t_node **a, char **arr, int arr_flag)
{
	long	lnb;
	int		i;

	i = 0;
	while (arr[i])
	{
		if (error_syntax(arr[i]))
			full_free(a, arr, arr_flag);
		lnb = ft_atol(arr[i]);
		if (lnb > INT_MAX || lnb < INT_MIN)
			full_free(a, arr, arr_flag);
		if (error_duplicates(*a, (int)lnb))
			full_free(a, arr, arr_flag);
		add_node(a, (int)lnb, arr);
		i++;
	}
	free(arr);
}

int	add_node(t_node **stack, int n, char **arr)
{
	t_node	*node;
	t_node	*last_node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (1);
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last(*stack);
		if (!last_node)
			return (1);
		last_node->next = node;
		node->prev = last_node;
	}
	free_arr(arr);
	return (0);
}
