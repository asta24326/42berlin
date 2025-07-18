/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:55:43 by wschafer          #+#    #+#             */
/*   Updated: 2025/06/10 11:55:47 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*cache;
	char			*str;
	char			*newline;
	ssize_t			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (cache)
			newline = ft_strchr(cache, '\n');
		else
			newline = NULL;
		if (newline)
			return (extract_line(&cache, newline));
		bytes = read_and_append(fd, &cache);
		str = handle_read_result(bytes, &cache);
		if (bytes <= 0)
			return (str);
	}
}

char	*handle_read_result(int bytes, char **cache)
{
	char	*str;

	if (bytes == -1)
	{
		free(*cache);
		*cache = NULL;
		return (NULL);
	}
	if (bytes == 0)
	{
		if (*cache && **cache != '\0')
		{
			str = ft_strdup(*cache);
			free (*cache);
			*cache = NULL;
			return (str);
		}
		free (*cache);
		*cache = NULL;
		return (NULL);
	}
	return (NULL);
}

ssize_t	read_and_append(int fd, char **cache)
{
	char	*buffer;
	char	*tmp;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes > 0)
	{
		buffer[bytes] = '\0';
		if (!*cache)
			*cache = ft_strdup("");
		tmp = ft_strjoin(*cache, buffer);
		if (!tmp)
		{
			free(buffer);
			free(*cache);
			*cache = NULL;
			return (-1);
		}
		free (*cache);
		*cache = tmp;
	}
	return (free(buffer), bytes);
}

char	*extract_line(char **cache, char *newline)
{
	char	*str;
	char	*rest;
	int		len;

	len = newline - *cache + 1;
	str = ft_substr(*cache, 0, len);
	rest = ft_strdup(newline + 1);
	free (*cache);
	*cache = rest;
	return (str);
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main()
// {
// 	char	*str;
// 	int		fd;

// 	fd = open("text.txt", O_RDONLY);

// 	if (fd == -1)
// 	{
// 		perror("open failed");
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		str = get_next_line(fd);
// 		if (str)
// 		{
// 			printf("%s", str);
// 			free (str);
// 		}
// 		else
// 			break;
// 	}
// 	close(fd);
// 	return (0);
// }
