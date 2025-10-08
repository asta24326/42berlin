#include "ft_list.h"

int	main(void)
{
	t_list	*list;

	list = create_node("First");
	list->next = create_node("Second");
	list->next->next = create_node("Third");

	putstr("List contains:");
	ft_list_foreach(list, putstr);

	free_list(list);
	return (0);
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list != NULL)
	{
		if (begin_list->data != NULL)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
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

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

void	putstr(void *data)
{
	char *s = (char *)data;
	if (!*s || !s)
		return ;
	while (*s)
		write(1, s++, 1);
	write(1, "\n", 1);
}