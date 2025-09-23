/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:25:47 by asharafe          #+#    #+#             */
/*   Updated: 2025/09/23 14:23:10 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
// 	int		fd1 = open("test1.txt", O_RDONLY);
// 	int		fd2 = open("test2.txt", O_RDONLY);
// 	int		fd3 = open("test3.txt", O_RDONLY);
// 	char	*line1;
// 	char	*line2;
// 	char	*line3;
// 	int		done1 = 0;
// 	int		done2 = 0;
// 	int		done3 = 0;
//
// 	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
// 	{
// 		if (fd1 >= 0) 
// 			close(fd1);
// 		if (fd2 >= 0) 
// 			close(fd2);
// 		if (fd3 >= 0) 
// 			close(fd3);
// 		printf("Error opening file\n");
// 		return (1);
// 	}
// 	while (!done1 || !done2 || !done3)
// 	{
// 		if (!done1)
// 		{
// 			line1 = get_next_line(fd1);
// 			if (line1)
// 				printf("fd1: %s", line1);
// 			if(!line1)
// 			{
// 				close(fd1);
// 				done1 = 1;
// 			}
// 			if (line1)
// 				free(line1);
// 		}
// 		if (!done2)
// 		{
// 			line2 = get_next_line(fd2);
// 			if (line2)
// 				printf("fd2: %s", line2);
// 			if(!line2)
// 			{
// 				close(fd2);
// 				done2 = 1;
// 			}
// 			if (line2)
// 				free(line2);
// 		}
// 		if (!done3)
// 		{
// 			line3 = get_next_line(fd3);
// 			if (line3)
// 				printf("fd3: %s", line3);
// 			if(!line3)
// 			{
// 				close(fd3);
// 				done3 = 1;
// 			}
// 			if (line3)
// 				free(line3);
// 		}
// 	}
// 	return (0);
// }

char	*get_next_line(int fd)
{
	static char	*cache[FD_MAX];
	char		*buffer;
	char		*new_line_start;
	ssize_t		read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (cache[fd])
			new_line_start = ft_strchr(cache[fd], '\n');
		else
			new_line_start = NULL;
		if (new_line_start)
			return (ft_extract_line(&cache[fd], cache[fd], new_line_start));
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			return (ft_read_results(&cache[fd], &buffer, read_bytes));
		if (!ft_merge_read(&cache[fd], &buffer, read_bytes))
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
		ft_full_free(cache, buffer);
		return (NULL);
	}
	ft_full_free(cache, buffer);
	*cache = temp;
	return (temp);
}

char	*ft_read_results(char **cache, char **buffer, ssize_t read_bytes)
{
	char	*line_return;

	if (read_bytes == -1)
		return (ft_full_free(cache, buffer));
	if (read_bytes == 0)
	{
		if (*cache && (*cache)[0] != '\0')
		{
			line_return = ft_strdup(*cache);
			ft_full_free(cache, buffer);
			return (line_return);
		}
		return (ft_full_free(cache, buffer));
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

void	*ft_full_free(char **cache, char **buffer)
{
	free (*cache);
	free (*buffer);
	*cache = NULL;
	return (NULL);
}
