/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:55:17 by asharafe          #+#    #+#             */
/*   Updated: 2025/11/15 17:02:04 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* PART 1 */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strcpy(char *dst, const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);

/* PART 2 */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(const char *s, char delim);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* FT_PRINTF */
int		ft_printf(const char *s, ...);
int		ft_print_arg(va_list args, char c);
int		ft_hex_sort(va_list args, char c);
int		ft_ptr_print(void *ptr, char *base);
int		ft_putnbr_hex(uintptr_t nbr, char *base);
int		ft_print_str(va_list args);
int		ft_print_char(va_list args, char c);
int		ft_print_int_dec(va_list args);
int		ft_putnbr_u(unsigned int nbr);

/* BONUS */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

/* get_next_line.c */
char	*get_next_line(int fd);
char	*ft_extract_line(char **cache_update, char *cache, char *n_address);
char	*ft_read_results(char **cache, char **buffer, ssize_t read_bytes);
char	*ft_merge_read(char **cache, char **buffer, size_t read_bytes);
void	*ft_full_free_gnl(char **cache, char **buffer);

#endif