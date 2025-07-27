/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:49:15 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:49:17 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);

int	main(void)
{
	int		value1 = 42;
	int		value2 = 100;
	int		value3 = 333;

	t_list	*lst = NULL; // linked list 
	t_list	*node1 = ft_lstnew(&value1); // node: [content=42, next=NULL]
	t_list	*node2 = ft_lstnew(&value2); // node: [content=42, next=NULL]
	t_list	*node3 = ft_lstnew(&value3); // node: [content=42, next=NULL]
	t_list	*current;
	t_list	*temp = lst;

	if (!node1 || !node2 || !node3)
	{
		printf("Error: Failed to create nodes\n");
		free(node1);
		free(node2);
		free(node3);
		return (1);
	}
	
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node3);
	ft_lstadd_front(&lst, node1);

	printf("node1 content: %d\n", *(int *)(node1->content));
	printf("node2 content: %d\n", *(int *)(node2->content));
	printf("node3 content: %d\n", *(int *)(node3->content));

	current = lst;
	while (current)
	{
		printf("Linked list: %d\n", *(int *)current->content);
		current = current->next;
	}

	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp); 
	}
	return (0);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);

	new->content = content;
	new->next = NULL;
	return (new);
}
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
