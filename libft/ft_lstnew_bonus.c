/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:49:50 by asharafe          #+#    #+#             */
/*   Updated: 2025/06/19 11:49:51 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

t_list	*ft_lstnew(void *content);

int	main(void)
{
	int	value1;
	int	value2;

	value1 = 42;
	value2 = 100;

	t_list	*new1;
	t_list	*new2;

	new1 = ft_lstnew(&value1);
	new2 = ft_lstnew(&value2);

	if(new1)
		printf("new1 content: %d\n", *(int *)(new1->content));
	if(new2)
		printf("new1 content: %d\n", *(int *)(new2->content));

	free (new1);
	free (new2);

	return (0);
}
*/

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
