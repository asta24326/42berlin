/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:53:14 by asharafe          #+#    #+#             */
/*   Updated: 2025/11/15 17:22:47 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
/*
ft_init_mlx - creates a window and loading textures
mlx_key_hook - to listen to keys press & handle
mlx_hook - Red cross event
mlx_loop - starts of mlx loop
*/

int	main(int ac, char **av)
{
	t_data	game;

	ft_bzero(&game, sizeof(game));
	ft_input_check(ac, av, &game);
	ft_map_init(av[1], &game);
	ft_check_map_size(&game);
	ft_check_map_containers(&game);
	ft_check_map_reach(&game);
	ft_find_player(&game);
	ft_init_mlx(&game, av);
	mlx_key_hook(game.mlx_win, ft_key_handler, &game);
	mlx_hook(game.mlx_win, 17, 0, ft_close_game, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
