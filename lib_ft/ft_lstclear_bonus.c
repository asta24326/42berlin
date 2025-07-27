/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:49:20 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:49:24 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

void	custom_free(void *content);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list	*lst, void (*del)(void	*));
t_list	*ft_lstnew(void *content);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int	main(void)
{
	char	*str1 = (char *)malloc(10);
	if (!str1)
	{
		printf("Error: Failed to create str\n");
		return (1);
	}
	char	*str2 = (char *)malloc(10);
	if (!str2)
	{
		printf("Error: Failed to create str\n");
		free(str1);
		return (1);
	}
	char	*str3 = (char *)malloc(10);
	if (!str3)
	{
		printf("Error: Failed to create str\n");
		free(str1);
		free(str2);
		return (1);
	}
	char	*src1 = "Node1";
	char	*src2 = "Node2";
	char	*src3 = "Node3";
	ft_strlcpy(str1, src1, ft_strlen(src1) + 1);
	ft_strlcpy(str2, src2, ft_strlen(src2) + 1);
	ft_strlcpy(str3, src3, ft_strlen(src3) + 1);

	t_list	*node1 = ft_lstnew(str1); // node: [content=Node1, next=NULL]
	if (!node1)
	{
		printf("Error: Failed to create node\n");
		free(str1);
		free(str2);
		free(str3);
		return (1);
	}
	t_list	*node2 = ft_lstnew(str2); // node: [content=Node2, next=NULL]
	if (!node2)
	{
		printf("Error: Failed to create node\n");
		free(node1);
		free(str1);
		free(str2);
		free(str3);
		return (1);
	}
	t_list	*node3 = ft_lstnew(str3); // node: [content=Node3, next=NULL]
	if (!node3)
	{
		printf("Error: Failed to create node\n");
		free(node1);
		free(node2);
		free(str3);
		free(str1);
		free(str2);
		return (1);
	}
	
	t_list	*lst = NULL; // linked list
	ft_lstadd_front(&lst, node3);
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node1);

	t_list	*current = lst;
	while (current)
	{
		printf("Node content before deletion: %s (address: %p)\n", 
		(char *)current->content, current->content);
		current = current->next;
	}
	
	ft_lstclear(&lst, custom_free);

	printf("Nodes deleted\n");
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_lstdelone(t_list	*lst, void (*del)(void	*))
{
	if (!lst || !del)
		return ;
	
	del(lst->content);
	free (lst);
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if(!lst || !new)
		return;
	new->next = *lst;
	*lst = new;
}

void	custom_free(void *content)
{
	if (content)
	{
		printf("Freeing content at this address %p\n", content);
		free (content);
	}
}
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
	*lst = NULL;
}
