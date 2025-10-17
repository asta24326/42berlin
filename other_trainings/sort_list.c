/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}
*/

#include <stdio.h>
#include <unistd.h>
#include "sort_list.h"

int		ascending(int a, int b);
t_list	*sort_list(t_list *lst, int (*cmp)(int, int));
t_list	*new_node(int data);

int	main(void)
{
	// Creating: 64->34->25->12->22->11->1
	t_list	*lst = new_node(64);
	lst->next = new_node(34);
	lst->next->next = new_node(25);
	lst->next->next->next = new_node(12);
	lst->next->next->next->next = new_node(22);
	lst->next->next->next->next->next = new_node(11);
	lst->next->next->next->next->next->next = new_node(1);
    
	printf("Before: ");
	t_list	*tmp = lst;
	while (tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");

	lst = sort_list(lst, &ascending);

	printf("After: ");
	tmp = lst;
	while (tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
	return (0);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*head;
	int		temp;
	int	i;
	t_list	*print;

	i = 1;
	head = lst;
	while (lst != NULL && lst->next != NULL)
	{
		printf("Attempt: %d\n", i++);
		printf("Current node: %d\n", lst->data);
		printf("Before attempt: ");
		print = head;
		while (print)
		{
			printf("%d ", print->data);
			print = print->next;
		}
		printf("\n");

		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			temp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = temp;
			lst = head;
		}
		else
			lst = lst->next;
		printf("After attempt: ");
		print = head;
		while (print)
		{
			printf("%d ", print->data);
			print = print->next;
		}
		printf("\n");
		printf("\n");

	}
	return (head);
}

int	ascending(int a, int b)
{
	return (a <= b);
}

t_list	*new_node(int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node ->data = data;
	node->next = NULL;
	return (node);
}