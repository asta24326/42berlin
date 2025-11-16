/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:03:04 by asharafe          #+#    #+#             */
/*   Updated: 2025/11/15 17:02:05 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Additional libraries
# include "../libraries/mlx/mlx.h"
# include "../libraries/mlx/mlx_int.h"
# include "../libraries/libft/libft.h"

// std libraries
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

// Macroses
# define WIDTH			64
# define HEIGHT			64

// Structures
typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_pic
{
	void		*xpm_ptr;
	int			x;
	int			y;
}	t_pic;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			collects;
	int			exit;
	int			players;
	t_pos		player;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			moves;
	int			map_fd;
	t_map		map;
	t_pic		wall;
	t_pic		wall_top;
	t_pic		ground;
	t_pic		collect;
	t_pic		finish;
	t_pic		player;
}	t_data;

// error_and_free.c
void		ft_custom_error(char *msg, t_data *game, int fd_map);
void		ft_full_free(char **arr);
void		ft_free_map(t_data *game);

// map_containers_check.c
void		ft_check_map_containers(t_data *game);
void		ft_find_player(t_data *game);

// map_init.c
void		ft_input_check(int ac, char **av, t_data *game);
void		ft_map_init(char *path, t_data *game);
void		ft_check_map_size(t_data *game);

// map_reach_check.c
void		ft_check_map_reach(t_data *game);
void		ft_find_player(t_data *game);

// mlx_init.c
void		ft_init_mlx(t_data *game, char **av);
void		ft_render_map(t_data *game);
void		ft_put_image(t_data *game, t_pic *pic, int x, int y);

// events_handle.c
int			ft_key_handler(int keycode, void *param);
int			ft_close_game(t_data *game);

// load_textures.c
void		ft_render_top_wall(t_data *game);
void		ft_load_texture(t_data *game, t_pic *pic, char *path);
void		ft_load_textures(t_data *game);

#endif
