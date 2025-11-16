/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reach_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 23:21:24 by asharafe          #+#    #+#             */
/*   Updated: 2025/11/15 14:16:53 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	**ft_copy_map(t_data *game);
static void	ft_flood_fill(t_data *game, char **copy, int x, int y);
static int	ft_in_map(t_data *game, int x, int y);

static char	**ft_copy_map(t_data *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!copy)
		ft_custom_error("malloc failed", game, -1);
	i = 0;
	while (i < game->map.rows)
	{
		copy[i] = ft_strdup(game->map.full[i]);
		if (!copy[i])
			ft_custom_error("malloc failed", game, -1);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	ft_flood_fill(t_data *game, char **copy, int x, int y)
{
	if (x < 1 || (x >= game->map.columns - 1)
		|| y < 1 || y >= game->map.rows - 1)
		return ;
	if (copy[y][x] == '1' || copy[y][x] == 'V')
		return ;
	copy[y][x] = 'V';
	ft_flood_fill(game, copy, x - 1, y);
	ft_flood_fill(game, copy, x + 1, y);
	ft_flood_fill(game, copy, x, y - 1);
	ft_flood_fill(game, copy, x, y + 1);
}

static int	ft_in_map(t_data *game, int x, int y)
{
	if ((x >= 1 && x < (game->map.columns - 1))
		&& (y >= 1 && y < (game->map.rows - 1)))
		return (1);
	return (0);
}

void	ft_check_map_reach(t_data *game)
{
	char	**copy;
	int		i;
	int		j;

	ft_find_player(game);
	if (!(ft_in_map(game, game->map.player.x, game->map.player.y)))
		ft_custom_error("player's postiton not inside walls", game, -1);
	copy = ft_copy_map(game);
	ft_flood_fill(game, copy, game->map.player.x, game->map.player.y);
	i = 1;
	while (i < game->map.rows - 1)
	{
		j = 1;
		while (j < game->map.columns - 1)
		{
			if (copy[i][j] != 'V' && copy[i][j] != '1')
			{
				ft_full_free(copy);
				ft_custom_error("collectibles not reachable", game, -1);
			}
			j++;
		}
		i++;
	}
	ft_full_free(copy);
}

void	ft_find_player(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
		{
			if (game->map.full[i][j] == 'P')
			{
				game->map.player.x = j;
				game->map.player.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	ft_custom_error("no player position", game, -1);
}
