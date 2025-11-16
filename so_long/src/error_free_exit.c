/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:43:11 by asharafe          #+#    #+#             */
/*   Updated: 2025/11/15 19:22:22 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_custom_error(char *msg, t_data *game, int fd_map)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\n", 1);
	if (game)
		ft_free_map(game);
	if (fd_map > 2)
		close (fd_map);
	exit (1);
}

void	ft_free_map(t_data *game)
{
	int	i;

	i = 0;
	if (game->map.full == NULL)
		return ;
	while (game->map.full[i])
	{
		free(game->map.full[i]);
		i++;
	}
	free(game->map.full);
}

void	ft_full_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_close_game(t_data *game)
{
	if (game->player.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.xpm_ptr);
	if (game->wall_top.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->wall_top.xpm_ptr);
	if (game->ground.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->ground.xpm_ptr);
	if (game->wall.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	if (game->collect.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->collect.xpm_ptr);
	if (game->finish.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->finish.xpm_ptr);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	if (game->map_fd > 2)
		close (game->map_fd);
	ft_free_map(game);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}
