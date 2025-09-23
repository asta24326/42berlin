/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:53:41 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/09/21 15:53:03 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	full_free(t_node **stack, char **arr, int arr_flag)
{
	free_stack(stack);
	if (arr_flag)
	{
		free_arr(arr);
		free(arr);
	}
	ft_printf("Error\n");
	exit(1);
}

void	free_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
}

int	error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-'
			|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-')
		&& !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

int	error_duplicates(t_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}
