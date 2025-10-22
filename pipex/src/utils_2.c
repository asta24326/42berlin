#include "pipex.h"

void	ft_free_arr(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	ft_custom_exit(char *exit_msg)
{
	ft_putstr_fd(exit_msg, 2);
	exit (1);
}

int	ft_valid_pid(pid_t pid)
{
	if (pid == -1)
	{
		ft_putstr_fd("error: fork failed\n", 2);
		return (1);
	}
	return (0);
}
