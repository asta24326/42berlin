/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:43:05 by asharafe          #+#    #+#             */
/*   Updated: 2025/11/15 17:24:46 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*ft_trim_line(char *s);
static void	ft_count_map_rows(char *path, t_data *game, int	*fd_map);
static char	*ft_read_trimmed_line(int fd);

static void	ft_count_map_rows(char *path, t_data *game, int	*fd_map)
{
	char	*parsed_line;

	game->map.rows = 0;
	parsed_line = get_next_line(*fd_map);
	while (parsed_line)
	{
		game->map.rows += 1;
		free(parsed_line);
		parsed_line = get_next_line(*fd_map);
	}
	close(*fd_map);
	*fd_map = open(path, O_RDONLY);
}

static char	*ft_trim_line(char *s)
{
	int	s_len;

	s_len = ft_strlen(s);
	if (s_len > 0 && s[s_len - 1] == '\n')
		s[s_len - 1] = '\0';
	return (s);
}

static char	*ft_read_trimmed_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	ft_trim_line(line);
	return (line);
}

void	ft_map_init(char *path, t_data *game)
{
	int		i;
	char	*parsed_line;

	game->map_fd = open(path, O_RDONLY);
	if (game->map_fd == -1)
		ft_custom_error("map not opened/not exist", game, -1);
	ft_count_map_rows(path, game, &game->map_fd);
	if (game->map.rows < 5)
		ft_custom_error("map rows < 5", game, game->map_fd);
	game->map.full = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!game->map.full)
		ft_custom_error("malloc failed", game, game->map_fd);
	i = 0;
	while (i < game->map.rows)
	{
		parsed_line = ft_read_trimmed_line(game->map_fd);
		if (!parsed_line)
			ft_custom_error("gnl failed", game, game->map_fd);
		game->map.full[i++] = ft_strdup(parsed_line);
		free(parsed_line);
	}
	game->map.full[i] = NULL;
	get_next_line(-1);
	close(game->map_fd);
}

void	ft_check_map_size(t_data *game)
{
	int			i;
	size_t		line_len;
	int			first_line;

	i = 0;
	first_line = 1;
	line_len = 0;
	while (game->map.full[i])
	{
		if (first_line)
		{
			line_len = ft_strlen(game->map.full[i]);
			if (line_len < 5)
				ft_custom_error("map columns < 5", game, -1);
			first_line = 0;
		}
		else
			if (line_len != ft_strlen(game->map.full[i]))
				ft_custom_error("different lines lengths", game, -1);
		i++;
	}
	game->map.columns = line_len;
}
