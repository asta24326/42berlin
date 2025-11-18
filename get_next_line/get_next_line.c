/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:25:47 by asharafe          #+#    #+#             */
/*   Updated: 2025/11/16 18:16:18 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

// #include <stdio.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error opening file\n");
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line)
// 		{
// 			printf("String is: %s", line);
// 			free(line);
// 		}
// 		else
// 			break ;
// 	}
// 	close(fd);
// 	return (0);
// }

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*buffer;
	char		*n_address;
	ssize_t		read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (cache)
			n_address = ft_strchr(cache, '\n');
		else
			n_address = NULL;
		if (n_address)
			return (ft_extract_line(&cache, cache, n_address));
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			return (ft_handle_read_results(&cache, &buffer, read_bytes));
		if (!ft_append_read(&cache, &buffer, read_bytes))
			return (NULL);
	}
}

char	*ft_extract_line(char **cache_update, char *cache, char *n_address)
{
	char		*line_return;
	char		*cache_leftover;
	size_t		line_len;

	line_len = n_address - cache + 1;
	line_return = ft_substr(cache, 0, line_len);
	cache_leftover = ft_strdup(n_address + 1);
	if (!cache_leftover)
	{
		free(line_return);
		free(*cache_update);
		*cache_update = NULL;
		return (NULL);
	}
	free(*cache_update);
	*cache_update = cache_leftover;
	return (line_return);
}

int	ft_append_read(char **cache, char **buffer, size_t read_bytes)
{
	char	*joined_str;

	(*buffer)[read_bytes] = '\0';
	if (!*cache)
		*cache = ft_strdup("");
	joined_str = ft_strjoin(*cache, *buffer);
	if (!joined_str)
	{
		ft_full_free(cache, buffer);
		return (0);
	}
	ft_full_free(cache, buffer);
	*cache = joined_str;
	return (1);
}

char	*ft_handle_read_results(char **cache, char **buffer, ssize_t read_bytes)
{
	char	*line_return;

	if (read_bytes == -1)
	{
		ft_full_free(cache, buffer);
		return (NULL);
	}
	if (read_bytes == 0)
	{
		if (*cache && (*cache)[0] != '\0')
		{
			line_return = ft_strdup(*cache);
			ft_full_free(cache, buffer);
			return (line_return);
		}
		ft_full_free(cache, buffer);
	}
	return (NULL);
}

void	ft_full_free(char **cache, char **buffer)
{
	if (cache && *cache)
	{
		free(*cache);
		*cache = NULL;
	}
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
}
