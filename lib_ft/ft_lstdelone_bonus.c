/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:49:28 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:49:29 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

t_list	*ft_lstnew(void *content);
void	ft_lstdelone(t_list	*lst, void (*del)(void	*));
void	custom_free(void *content);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

int	main(void)
{
	char	*str = (char *)malloc(10);
	char	*src = "Test";
	
	if (!str)
	{
		printf("Error: Failed to create str\n");
		return (1);
	}
	ft_strlcpy(str, src, ft_strlen(src) + 1);

	t_list	*node = ft_lstnew(str); // node: [content=42, next=NULL]
	if (!node)
	{
		printf("Error: Failed to create node\n");
		free(str);
		return (1);
	}
	
	printf("Node content before deletion: %s(address: %p)\n",
	(char *)node->content, node->content);

	ft_lstdelone(node, custom_free);
	node = NULL;

	printf("Node deleted\n");
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

void	ft_lstdelone(t_list	*lst, void (*del)(void	*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free (lst);
}
