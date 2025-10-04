/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:49:02 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:49:11 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);

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

	if (!node1)
	{
		printf("Error: Failed to create node1\n");
		return (1);
	}
	if (!node2)
	{
		printf("Error: Failed to create node2\n");
		return (1);
	}
	if (!node3)
	{
		printf("Error: Failed to create node3\n");
		return (1);
	}
	
	ft_lstadd_back(&lst, node3);
	ft_lstadd_back(&lst, node2);
	ft_lstadd_back(&lst, node1);
	
	//printf("node1 content: %d\n", *(int *)(node1->content));
	//printf("node2 content: %d\n", *(int *)(node2->content));
	//printf("node3 content: %d\n", *(int *)(node3->content));
	
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

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (0);

	while (lst->next)
		lst = lst->next;
	return (lst);
}
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = new;
}
