/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:49:54 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:49:55 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

int	ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);

int	main(void)
{
	int		value1 = 42;
	int		value2 = 100;
	int		value3 = 333;
	int		value4 = 999;

	t_list	*lst = NULL; // linked list 
	t_list	*node1 = ft_lstnew(&value1); // node: [content=42, next=NULL]
	t_list	*node2 = ft_lstnew(&value2); // node: [content=42, next=NULL]
	t_list	*node3 = ft_lstnew(&value3); // node: [content=42, next=NULL]
	t_list	*node4 = ft_lstnew(&value4); // node: [content=42, next=NULL]
	t_list	*current;
	t_list	*temp = lst;

	if (!node1 || !node2 || !node3 || !node4)
	{
		printf("Error: Failed to create nodes\n");
		free(node1);
		free(node2);
		free(node3);
		free(node4);
		return (1);
	}
	
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node3);
	ft_lstadd_front(&lst, node1);
	ft_lstadd_front(&lst, node4);

	printf("node1 content: %d\n", *(int *)(node1->content));
	printf("node2 content: %d\n", *(int *)(node2->content));
	printf("node3 content: %d\n", *(int *)(node3->content));
	printf("node4 content: %d\n", *(int *)(node4->content));
	current = lst;
	while (current)
	{
		printf("Linked list: %d\n", *(int *)current->content);
		current = current->next;
	}

	printf("Size of linked list is: %d\n", ft_lstsize(lst));

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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if(!lst || !new)
		return;
	new->next = *lst;
	*lst = new;
}
*/

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*ptr;

	if (lst == NULL)
		return (0);
	ptr = lst;
	size = 0;
	while (ptr)
	{
		size++;
		ptr = ptr->next;
	}
	return (size);
}
