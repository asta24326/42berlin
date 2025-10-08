#ifndef FT_LISTFOREACH_H
# define FT_LISTFOREACH_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
t_list	*create_node(void *data);
void	free_list(t_list *list);
void	putstr(void *data);

#endif
