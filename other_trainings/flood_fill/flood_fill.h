
#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_point
{
	int	column;
	int	row;
} t_point;


char	**make_tab(char **zone, t_point size);
void	flood_fill(char **tab, t_point size, t_point begin);
void	fill_tab(char **tab, t_point size, t_point current, char target);

#endif