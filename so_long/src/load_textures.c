/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:13:34 by asharafe          #+#    #+#             */
/*   Updated: 2025/11/15 15:15:15 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_render_top_wall(t_data *game)
{
	int	x;

	x = 0;
	while (x < game->map.columns)
	{
		ft_put_image(game, &game->wall_top, x, 0);
		x++;
	}
}

void	ft_load_texture(t_data *game, t_pic *pic, char *path)
{
	pic->xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, 
			&pic->x, &pic->y);
	if (!pic->xpm_ptr)
		ft_custom_error("failed to load xpm", game, -1);
}

void	ft_load_textures(t_data *game)
{
	ft_load_texture(game, &game->wall_top, "./xpm_files/fence_top_bg.xpm");
	ft_load_texture(game, &game->player, "./xpm_files/player_bg.xpm");
	ft_load_texture(game, &game->ground, "./xpm_files/grass.xpm");
	ft_load_texture(game, &game->wall, "./xpm_files/fence_bg.xpm");
	ft_load_texture(game, &game->collect, "./xpm_files/poo_bg.xpm");
	ft_load_texture(game, &game->finish, "./xpm_files/exit_bg.xpm");
}
