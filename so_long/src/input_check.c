/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:06:19 by asharafe          #+#    #+#             */
/*   Updated: 2025/11/15 17:07:09 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_input_check(int ac, char **av, t_data *game)
{
	int		fd_map;
	size_t	path_len;
	size_t	bytes_read;
	char	buffer[1];

	if (ac != 2)
		ft_custom_error("expected input: ./so_long [map file]",
			game, -1);
	path_len = ft_strlen(av[1]);
	if (path_len < 4 || ft_strcmp(av[1] + (path_len - 4), ".ber") != 0)
		ft_custom_error("map file should have .ber extension", game, -1);
	fd_map = open(av[1], O_RDONLY);
	if (fd_map == -1)
		ft_custom_error("map opening failed or it doesn't exist",
			game, -1);
	bytes_read = read(fd_map, buffer, 1);
	if (bytes_read <= 0)
		ft_custom_error("map is empty", game, fd_map);
	close(fd_map);
}
