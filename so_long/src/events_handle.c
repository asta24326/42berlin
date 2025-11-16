/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:42:52 by asharafe          #+#    #+#             */
/*   Updated: 2025/11/15 16:04:18 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_update_tile(t_data *game, int x, int y, char tile);
static void	ft_get_new_coords(int keycode, int *new_x, 
				int *new_y, t_data *game);
static void	ft_apply_move(t_data *game, int new_x, int new_y);
static void	ft_player_move(t_data *game, int keycode, int x, int y);

static void	ft_update_tile(t_data *game, int x, int y, char tile)
{
	if (tile == '0')
		ft_put_image(game, &game->ground, x, y);
	if (tile == 'C')
		ft_put_image(game, &game->collect, x, y);
	if (tile == 'E')
		ft_put_image(game, &game->finish, x, y);
	if (tile == '1')
		ft_put_image(game, &game->wall, x, y);
}

static void	ft_get_new_coords(int keycode, int *new_x, int *new_y, t_data *game)
{
	int	x;
	int	y;

	x = *new_x;
	y = *new_y;
	if ((keycode == 'w' || keycode == 'W') && y > 0)
		*new_y = y - 1;
	else if ((keycode == 's' || keycode == 'S') && y < game->map.rows - 1)
		*new_y = y + 1;
	else if ((keycode == 'd' || keycode == 'D') && x < game->map.columns - 1)
		*new_x = x + 1;
	else if ((keycode == 'a' || keycode == 'A') && x > 0)
		*new_x = x - 1;
}

/* Apply the computed move: update map, player pos, collectibles and moves. */
static void	ft_apply_move(t_data *game, int new_x, int new_y)
{
	char	new_pos;
	char	old_pos;

	new_pos = game->map.full[new_y][new_x];
	old_pos = game->map.full[game->map.player.y][game->map.player.x];
	if (new_pos == '1')
		return ;
	if (new_pos == 'C')
		game->map.collects -= 1;
	if (old_pos == 'C')
		game->map.full[game->map.player.y][game->map.player.x] = '0';
	else if (old_pos == 'E')
		game->map.full[game->map.player.y][game->map.player.x] = 'E';
	ft_update_tile(game, game->map.player.x, game->map.player.y, old_pos);
	ft_put_image(game, &game->player, new_x, new_y);
	game->map.player.x = new_x;
	game->map.player.y = new_y;
	game->moves += 1;
	ft_printf("Player's moves: %d\n", game->moves);
	if (new_pos == 'E' && game->map.collects == 0)
		ft_close_game(game);
}

static void	ft_player_move(t_data *game, int keycode, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = x;
	new_y = y;
	ft_get_new_coords(keycode, &new_x, &new_y, game);
	ft_apply_move(game, new_x, new_y);
	ft_render_map(game);
}

int	ft_key_handler(int keycode, void *param)
{
	t_data	*game;
	int		x;
	int		y;

	game = (t_data *)param;
	x = game->map.player.x;
	y = game->map.player.y;
	if (keycode == 65307)
		ft_close_game(game);
	if (keycode == 'W' || keycode == 'w' || keycode == 'A' || keycode == 'a'
		|| keycode == 'S' || keycode == 's' || keycode == 'D' || keycode == 'd')
		ft_player_move(game, keycode, x, y);
	return (0);
}
