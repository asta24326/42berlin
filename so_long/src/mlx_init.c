/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:03:49 by asharafe          #+#    #+#             */
/*   Updated: 2025/11/15 16:26:00 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_put_image(t_data *game, t_pic *pic, int x, int y)
{
	if (!game || !game->mlx_ptr || !game->mlx_win)
		return ;
	if (!pic || !pic->xpm_ptr)
		return ;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, pic->xpm_ptr,
		x * WIDTH, y * HEIGHT);
}

void	ft_render_map(t_data *game)
{
	int	x;
	int	y;

	ft_render_top_wall(game);
	y = 1;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_put_image(game, &game->ground, x, y);
			if (game->map.full[y][x] == '1')
				ft_put_image(game, &game->wall, x, y);
			if (game->map.full[y][x] == 'C')
				ft_put_image(game, &game->collect, x, y);
			if (game->map.full[y][x] == 'E')
				ft_put_image(game, &game->finish, x, y);
			if (x == game->map.player.x && y == game->map.player.y)
				ft_put_image(game, &game->player, x, y);
			x++;
		}
		y++;
	}
}

void	ft_init_mlx(t_data *game, char **av)
{
	int	map_width;
	int	map_height;

	game->mlx_ptr = mlx_init();
	if (!(game->mlx_ptr))
		ft_custom_error("mlx_init failed", game, -1);
	map_width = game->map.columns * WIDTH;
	map_height = game->map.rows * HEIGHT;
	game->mlx_win = mlx_new_window(game->mlx_ptr, map_width, map_height, av[1]);
	if (!(game->mlx_win))
		ft_custom_error("mlx_new_window failed", game, -1);
	ft_load_textures(game);
	ft_render_map(game);
}
