/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 23:00:43 by aidarsharaf       #+#    #+#             */
/*   Updated: 2025/10/21 01:25:04 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../includes/libft/libft.h"
# include <unistd.h> // for pipe, fork, dup2, close
# include <sys/wait.h> // for waitpid
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> // for open
# include <stdlib.h> // for exit

/*	utils.c file	*/
int		*ft_init_fds(int argc, char **argv);
void	ft_exec(char *cmd, char **env);
char	*ft_getpath(char *cmd, char **env);
char	*ft_parse_env(char *name, char **env);
/*	utils_1.c file	*/
void	ft_exec_cmd_first(char *cmd, int *fds, char **env);
void	ft_exec_cmd_last(char *cmd, int *fds, char **env);
void	ft_close_fds(int *fds);
int		ft_open_file(char *file, int mode);
/*	utils_2 file	*/
void	ft_free_arr(char **arr);
void	ft_custom_exit(char *exit_msg);
int		ft_valid_pid(pid_t pid);

#endif