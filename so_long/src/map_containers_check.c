/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_containers_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:26:08 by asharafe          #+#    #+#             */
/*   Updated: 2025/11/15 14:02:11 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_check_item(t_data *game, char c);
static void	ft_check_walls(t_data *game);

static int	ft_check_item(t_data *game, char c)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y <= (game->map.rows - 1))
	{
		x = 0;
		while (game->map.full[y][x])
		{
			if (game->map.full[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	ft_check_walls(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i <= (game->map.rows - 1))
	{
		if ((game->map.full[i][0] != '1') ||
			(game->map.full[i][game->map.columns - 1] != '1'))
			ft_custom_error("map not covered by walls", game, -1);
		i++;
	}
	j = 0;
	while (game->map.full[0][j])
	{
		if ((game->map.full[0][j] != '1') ||
			(game->map.full[game->map.rows - 1][j] != '1'))
			ft_custom_error("map not covered by walls", game, -1);
		j++;
	}
}

void	ft_check_map_containers(t_data *game)
{
	game->map.collects = ft_check_item(game, 'C');
	game->map.exit = ft_check_item(game, 'E');
	game->map.players = ft_check_item(game, 'P');
	if (ft_check_item(game, '0') == 0)
		ft_custom_error("no free spaces on map", game, -1);
	if (game->map.collects < 1)
		ft_custom_error("no collectibles", game, -1);
	if (game->map.exit > 1 || game->map.exit == 0)
		ft_custom_error("no or more that one exit", game, -1);
	if (game->map.players > 1 || game->map.players == 0)
		ft_custom_error("no or more than 1 start postion", game, -1);
	ft_check_walls(game);
}
