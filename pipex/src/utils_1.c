#include "pipex.h"

// mode == 1 means it's first command and we'll write to pipe_fd[1]
// mode == 0 if we're reading from pipe_fd[0] and the write to STDOUT
void	ft_exec_cmd_first(char *cmd, int *fds, char **env)
{
	dup2(fds[2], STDIN_FILENO);
	dup2(fds[1], STDOUT_FILENO);
	ft_close_fds(fds);
	ft_exec(cmd, env);
}

void	ft_exec_cmd_last(char *cmd, int *fds, char **env)
{
	dup2(fds[0], STDIN_FILENO);
	dup2(fds[3], STDOUT_FILENO);
	ft_close_fds(fds);
	ft_exec(cmd, env);
}

void	ft_close_fds(int *fds)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		if (fds && fds[i] >= 0)
			close (fds[i]);
		i++;
	}
}

// "input == to read from it" mode, we send to function 0
//  "out == write to it" mode , we send to funciton 1
int	ft_open_file(char *file, int mode)
{
	int	res;

	if (mode == 0)
		res = open(file, O_RDONLY, 0777);
	if (mode == 1)
		res = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (res);
}
