/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 22:54:29 by asharafe          #+#    #+#             */
/*   Updated: 2025/09/20 21:26:05 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* stack creation */
/* ../utils/create_stack_a.c */
void	create_stack_a(t_node **a, char **argv, int arr_flag);
int		add_node(t_node **stack, int n);

/* split function */
/* ../utils/custom_split.c */
char	**custom_split(char *s, char c);
// static int		count_words(char *s, char c);
// static char	*extract_word(char *s, char c);
// static char	**free_arr(char **arr, int words);

/* errors */
/* ../utils/errors_handle.c */
void	full_free(t_node **stack, char **arr, int arr_flag);
void	free_stack(t_node **stack);
void	free_arr(char **arr);
int		error_syntax(char *str);
int		error_duplicates(t_node *a, int n);

/* get */
/* ../utils/get.c */
t_node	*get_prelast(t_node *top);
t_node	*get_last(t_node *top);
t_node	*get_max(t_node *stack);
t_node	*get_min(t_node *stack);
t_node	*get_cheapest(t_node *stack);

/* initialise 'a' nodes and move to 'b' */
/* ../utils/init_nodes_a.c */
void	init_nodes_a(t_node *a, t_node *b);
void	current_index(t_node *stack);
void	set_cheapest(t_node *stack);
// static void	set_target_a(t_node *a, t_node *b);
// static void	cost_analysis_a(t_node *a, t_node *b);

/* initialise 'b' nodes */
/* ../utils/init_nodes_b.c */
void	init_nodes_b(t_node *a, t_node *b);
//static void	set_target_b(t_node *a, t_node *b);

/* push */
/* ../utils/push.c */
void	pa(t_node **a, t_node **b, bool print);
void	pb(t_node **a, t_node **b, bool print);
// void	push(t_node **dst, t_node **src);

/* reverse rotate */
/* ../utils/rev_rotate.c */
void	rra(t_node	**a, bool print);
void	rrb(t_node	**b, bool print);
void	rrr(t_node **a, t_node **b, bool print);
// static void	rev_rotate(t_node **top);

/* rotate both */
/* ../utils/rotate_both.c */
void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node);
void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest_node);

/* rotate */
/* ../utils/rotate.c */
void	ra(t_node	**a, bool print);
void	rb(t_node	**b, bool print);
void	rr(t_node **a, t_node **b, bool print);
// static void	rotate(t_node **top);

/* sort stacks functions */
/* ../utils/sort_stacks.c */
void	sort_stacks(t_node **a, t_node **b);
void	prep_for_push(t_node **stack,
			t_node *cheapest_node, char stack_name);
// static void	move_a_to_b(t_node **a, t_node **b);
// static void	move_b_to_a(t_node **a, t_node **b);
// static void	min_on_top(t_node **a);

/* sort three algorithm */
/* ../utils/sort_three.c */
void	sort_three(t_node **a);

/* swap */
/* ../commands/swap.c */
void	sa(t_node **a, bool print);
void	sb(t_node **b, bool print);
void	ss(t_node **a, t_node **b, bool print);
// static void	swap(t_node **head);

/* utils */
/* ../utils.c */
bool	stack_sorted(t_node *stack);
int		stack_len(t_node *stack);
void	print_content(const t_node *stack);

#endif