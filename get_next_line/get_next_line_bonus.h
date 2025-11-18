/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:51:22 by asharafe          #+#    #+#             */
/*   Updated: 2025/11/16 18:16:36 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <unistd.h>
# include <stdlib.h>

/* get_next_line.c  */
char	*get_next_line(int fd);
char	*ft_extract_line(char **cache_update, char *cache, char *n_address);
char	*ft_handle_read_results(char **cache, 
			char **buffer, ssize_t read_bytes);
int		ft_append_read(char **cache, char **buffer, size_t read_bytes);
void	ft_full_free(char **cache, char **buffer);

/* get-next_line_utils.c */
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
