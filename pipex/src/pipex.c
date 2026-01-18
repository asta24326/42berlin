/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 22:26:41 by asharafe          #+#    #+#             */
/*   Updated: 2025/11/23 17:14:40 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		*fds;
	pid_t	pid1;
	pid_t	pid2;

	fds = ft_init_fds(argc, argv);
	if (pipe(fds) == -1)
		return (ft_close_fds(fds), free(fds), 1);
	pid1 = fork();
	if (ft_valid_pid(pid1))
		return (ft_close_fds(fds), free(fds), 1);
	if (pid1 == 0)
		ft_exec_cmd_first(argv[2], fds, env);
	else
	{
		close(fds[1]);
		wait(NULL);
		pid2 = fork();
		if (ft_valid_pid(pid2))
			return (ft_close_fds(fds), free(fds), 1);
		if (pid2 == 0)
			ft_exec_cmd_last(argv[argc - 2], fds, env);
		close(fds[0]);
		wait(NULL);
	}
	return (ft_close_fds(fds), free(fds), 0);
}

int	*ft_init_fds(int argc, char **argv)
{
	int	*fds_arr;

	if (argc != 5)
		ft_custom_exit("./pipex infile cmd1 cmd2 outfile\n");
	fds_arr = malloc(sizeof(int) * 4);
	if (!fds_arr)
		ft_custom_exit("pipex: memory allocation failed\n");
	fds_arr[2] = ft_open_file(argv[1], 0);
	if (fds_arr[2] == -1)
	{
		free(fds_arr);
		ft_custom_exit("pipex: error opening infile\n");
	}
	fds_arr[3] = ft_open_file(argv[argc - 1], 1);
	if (fds_arr[3] == -1)
	{
		close(fds_arr[2]);
		free(fds_arr);
		ft_custom_exit("pipex: error opening outfile\n");
	}
	return (fds_arr);
}

void	ft_exec(char *cmd, int *fds, char **env)
{
	char	**parsed_cmd;
	char	*exec_path;

	parsed_cmd = ft_split(cmd, ' ');
	if (!parsed_cmd)
	{
		free(fds);
		ft_custom_exit("pipex: memory allocation failed\n");
	}
	exec_path = ft_getpath(parsed_cmd[0], env);
	if (!exec_path || execve(exec_path, parsed_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putstr_fd(parsed_cmd[0], 2);
		ft_putstr_fd("\n", 2);
		ft_free_arr(parsed_cmd);
		free(fds);
		if (exec_path)
			free(exec_path);
		exit(127);
	}
}

// to find check the path and command existance and prepare path for execve
char	*ft_getpath(char *cmd, char **env)
{
	char	**allpaths;
	char	*path_prep;
	char	*exec_str;
	int		i;

	allpaths = ft_split(ft_parse_env("PATH", env), ':');
	if (!allpaths)
		return (NULL);
	i = -1;
	while (allpaths[++i])
	{
		path_prep = ft_strjoin(allpaths[i], "/");
		exec_str = ft_strjoin(path_prep, cmd);
		free (path_prep);
		if (access(exec_str, F_OK | X_OK) == 0)
			return (ft_free_arr(allpaths), exec_str);
		free (exec_str);
	}
	return (ft_free_arr(allpaths), NULL);
}

char	*ft_parse_env(char *name, char **env)
{
	int		i;
	int		j;
	char	*substr;

	if (!name || !env)
		return (NULL);
	i = -1;
	while (env[++i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		substr = ft_substr(env[i], 0, j);
		if (!substr)
			return (NULL);
		if ((ft_strcmp(substr, name)) == 0)
		{
			free(substr);
			return (&env[i][j + 1]);
		}
		free(substr);
	}
	return (NULL);
}
