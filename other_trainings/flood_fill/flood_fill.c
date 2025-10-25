/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:42:22 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/10/24 12:12:39 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

int	main(void)
{
	t_point	size = {10, 10};
	t_point	begin = {2, 2};
	char **tab;
	int	i;
	
	char *zone[]= {
	"1 1 1 1 1 1 1 1 0 0",
	"1 0 0 0 1 0 0 1 0 1",
	"1 0 0 0 0 0 0 0 0 1",
	"1 0 1 1 0 0 0 1 0 0",
	"1 1 1 0 0 0 0 1 1 1",
	"1 1 1 0 0 0 0 1 1 1",
	"1 1 1 0 0 0 0 1 1 1",
	"1 1 1 0 1 0 0 1 1 1",
	"1 1 1 0 0 1 0 1 0 1",
	"1 1 1 1 0 0 0 1 0 1",
	};
	i = 0;
	tab = make_tab(zone, size);
	while (i < size.row)
		printf("%s\n", tab[i++]);
	printf("\n");
	flood_fill(tab, size, begin);
	i = 0;
	while (i < size.row)
		printf("%s\n", tab[i++]);
	return (0);
}

char	**make_tab(char **zone, t_point size)
{
	char 	**new;
	int	input_i;
	int	input_j;
	int	arr_row;
	int	arr_column;
	
	input_i = 0;
	arr_row = 0;
	new = malloc(sizeof(char *) * size.row);// allocated array of arrays for future rows
	if (!new)
		return (NULL);
	while (arr_row < size.row)
	{
		new[arr_row] = malloc(sizeof(char) * (size.column + 1));//allocation in each row arr same length as column + 1
		if (!new[arr_row])
			return (NULL);
		arr_column = 0;
		input_j = 0;
		while (arr_column < size.column)//going through each place(column) in row
		{
			new[arr_row][arr_column] = zone[input_i][input_j * 2];//setting it in new arr
			input_j++;
			arr_column++;
		}
		new[arr_row][size.column] = '\0';
		arr_row++;
		input_i++;
	}
	return (new);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;

	target = tab[begin.column][begin.row];
	fill_tab(tab, size, begin, target);
}

void	fill_tab(char **tab, t_point size, t_point current, char target)
{
	if (current.column < 0 || current.column >= size.column || 
		current.row < 0 || current.row >= size.row)
		return ;
	if (tab[current.row][current.column] != target)// if it's a wall (1) or already painted (F)
		return ;
	tab[current.row][current.column] = 'F';
	fill_tab(tab, size, (t_point){current.column, current.row - 1}, target);// we check up
	fill_tab(tab, size, (t_point){current.column, current.row + 1}, target);// we check down
	fill_tab(tab, size, (t_point){current.column - 1, current.row}, target);//we check left
	fill_tab(tab, size, (t_point){current.column + 1, current.row}, target);//we check right
}
