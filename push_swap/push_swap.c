/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:49:55 by asharafe          #+#    #+#             */
/*   Updated: 2025/09/23 14:18:49 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		process_input(t_node **a, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (process_input(&a, argc, argv))
		return (1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, true);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	return (free_stack(&a), 0);
}

int	process_input(t_node **a, int argc, char **argv)
{
	char	**new_arr;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2 && argv[1][0] == 'B')
		return (1);
	else if (argc == 2)
	{
		new_arr = custom_split(argv[1], ' ');
		if (!new_arr)
			return (ft_printf("Error\n"), 1);
		create_stack_a(a, new_arr, 1);
	}
	else
		create_stack_a(a, argv + 1, 0);
	return (0);
}
