/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:25:47 by asharafe          #+#    #+#             */
/*   Updated: 2025/11/15 17:24:37 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdlib.h>
// #include <unistd.h>

// #include <stdio.h>
// #include <fcntl.h>

// char	*get_next_line(int fd);
// char	*extract_line(char **cache_update, char *cache, char *n_address);
// size_t	ft_strlen(const char *s);
// char	*ft_strchr(const char *s, int c);
// void	*full_free(char **cache, char **buffer);

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
	char		*new_line_start;
	ssize_t		read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(cache), cache = NULL, NULL);
	while (1)
	{
		if (cache)
			new_line_start = ft_strchr(cache, '\n');
		else
			new_line_start = NULL;
		if (new_line_start)
			return (ft_extract_line(&cache, cache, new_line_start));
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			return (ft_read_results(&cache, &buffer, read_bytes));
		if (!ft_merge_read(&cache, &buffer, read_bytes))
			return (NULL);
	}
}

char	*ft_merge_read(char **cache, char **buffer, size_t read_bytes)
{
	char	*temp;

	(*buffer)[read_bytes] = '\0';
	if (!*cache)
		*cache = ft_strdup("");
	temp = ft_strjoin(*cache, *buffer);
	if (!temp)
	{
		ft_full_free_gnl(cache, buffer);
		return (NULL);
	}
	ft_full_free_gnl(cache, buffer);
	*cache = temp;
	return (temp);
}

char	*ft_read_results(char **cache, char **buffer, ssize_t read_bytes)
{
	char	*line_return;

	if (read_bytes == -1)
		return (ft_full_free_gnl(cache, buffer));
	if (read_bytes == 0)
	{
		if (*cache && (*cache)[0] != '\0')
		{
			line_return = ft_strdup(*cache);
			free(*cache);
			*cache = NULL;
			free(*buffer);
			*buffer = NULL;
			return (line_return);
		}
		free(*cache);
		*cache = NULL;
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	return (NULL);
}

char	*ft_extract_line(char **cache_update, char *cache, char *n_address)
{
	char		*line_return;
	char		*temp;
	size_t		line_len;

	line_len = n_address - cache + 1;
	line_return = ft_substr(cache, 0, line_len);
	temp = ft_strdup(n_address + 1);
	if (!temp)
	{
		free(line_return);
		free(*cache_update);
		*cache_update = NULL;
		return (NULL);
	}
	free(*cache_update);
	*cache_update = temp;
	return (line_return);
}

void	*ft_full_free_gnl(char **cache, char **buffer)
{
	if (cache && *cache)
	{
		free (*cache);
		*cache = NULL;
	}
	if (buffer && *buffer)
	{
		free (*buffer);
		*buffer = NULL;
	}
	return (NULL);
}
