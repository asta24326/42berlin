/*
	Assignment name : ft_list_remove_if
	Expected files: It_list_remove_if.c
	Allowed functions: free
	
	Write a function called it_list_remove_if that removes from the passed list any element the data of which is "equal" to the reference data.
	
	It will be declared as follows :
	void it_list_remove_ift_list **begin_list, void *data_ref, int (*cmp)());

	cmp takes two void* and returns 0 when both parameters are equal.
	
	You have to use the it_list.h file, which will contain:
	$>cat ft_list.h typedef struct
	s_list
	
	struct s_list void
	}
	$>
	*next;
	*data; t_list;

*/

#include "ft_list_remove.h"

int	main(void)
{
	t_list	*list;
	char	*data_ref;

	data_ref = "Second";
	list = create_node("First");
	list->next = create_node("Second");
	list->next->next = create_node("First");
	list->next->next->next = create_node("Third");
	list->next->next->next->next = create_node("Five");

	ft_putstr("Before: \n");
	while(list->data)
	{
		printf("%s \n", (char *)list->data);
		list = list->next;
	}

	ft_putstr("After: \n");
	ft_list_remove_if(&list, "First", cmp_str);
	while(list->data)
	{
		printf("%s \n", (char *)list->data);
		list = list->next;
	}
	free(list);
	return (0);
}

// ??? WHY "int (*cmp)()" ???
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*prev;
	t_list	*temp;

	current = *begin_list;
	prev = NULL;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	
	while (current)
	{
		if (cmp(current->data, data_ref) == 0) // if data is similar, cmp returns 0
		{
			temp = current;
			// if it's head of the list
			if (prev == NULL)
				*begin_list = current->next;
			else
				prev->next = current->next; // so we link prev and next - means we unlink the node
			// move to the next one
			current = temp->next;
			free (temp);
		}
		else
		{
			//if data is not similar
			prev = current;
			current = current->next;
		}
	}
}

t_list	*create_node(void *data)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	if (new_node)
	{
		new_node->data = data;
		new_node->next = NULL;
	}
	return (new_node);
}

void	free_list(t_list *list)
{
	t_list	*temp;

	while (list->data)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

int	cmp_str(void *data1, void *data2)
{
	char	*s1;
	char	*s2;

	s1 = (char *)data1;
	s2 = (char *)data2;

	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
	write(1, "\n", 1);
}