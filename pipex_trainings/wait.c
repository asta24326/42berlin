#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	pid_t	ret_value;
	pid_t	child_pid;
	int		wstatus;

	ret_value = fork();

	if (ret_value == -1)
		return (perror("fork failed"), -1);
	
	if (ret_value == 0)
	{
		printf("I'm a child\n");
		printf("My parent pid: %d\n", getppid());
		printf("My pid: %d\n", getpid());
		return	(-15);
	}
	else
	{
		printf("I'm a parent\n");
		printf("My parent pid: %d\n", getppid());
		printf("My pid: %d\n", getpid());
		

		child_pid = wait(&wstatus); // the only argument will be wstatus, and we will read pid of child process
		if (child_pid == -1)
		{
			perror("wait failed");
			exit(-1);
		}
		if (!WIFEXITED(wstatus))// check if child process ended normally, so the parent will also end
		{
			printf("child not exited\n");
			exit(0); 
		}
		printf("child %d returned %d\n", child_pid, WEXITSTATUS(wstatus));
		exit (0);
	}
	return (0);
}

