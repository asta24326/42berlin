#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	pid_t	ret_value;

	ret_value = fork();

	if (ret_value == -1)
		return (perror("fork failed"), -1);
	if (ret_value == 0)
	{
		printf("I'm a child\n");
		printf("My parent pid: %d\n", getppid());
		printf("My pid: %d\n", getpid());
		return (0);
	}
	else
	{
		printf("I'm a parent\n");
		printf("My parent pid: %d\n", getppid());
		printf("My pid: %d\n", getpid());
		return (0);
	}
	return (0);
}

