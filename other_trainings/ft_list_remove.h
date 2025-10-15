#ifndef FT_LIST_REMOVE_H
# define FT_LIST_REMOVE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
t_list	*create_node(void *data);
void	free_list(t_list *list);
int		cmp_str(void *data1, void *data2);
void	ft_putstr(char *s);


#endif