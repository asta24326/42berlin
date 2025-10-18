#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	pid_t	pid1;
	pid_t	pid2;
	int		wstatus1;
	int		wstatus2;

	pid1 = fork();

	if (pid1 == 0)
	{
		printf("Child (first command): finished with 0\n");
		return (0);
	}

	pid2 = fork();

	if (pid2 == 0)
	{
		printf("Child (second command): finished with 1\n");
		return (1);
	}

	waitpid(pid1, &wstatus1, 0);
	
	if (WIFEXITED(wstatus1))
		printf("First command finished with statu:%d\n", WEXITSTATUS(wstatus1));

	waitpid(pid2, &wstatus2, 0);
	
	if (WIFEXITED(wstatus2))
		printf("Second command finished with status:%d\n", WEXITSTATUS(wstatus2));

	return (0);
}




// // waiting for 2 kids
// int	main(int argc, char **argv)
// {
// 	pid_t	ret_value;
// 	pid_t	child_pid;
// 	int		wstatus;

// 	ret_value = fork();

// 	if (ret_value == -1)
// 		return (perror("fork failed"), -1);
	
// 	if (ret_value == 0)
// 	{
// 		printf("I'm a child\n");
// 		printf("My parent pid: %d\n", getppid());
// 		printf("My pid: %d\n", getpid());
// 		return	(-15);
// 	}
// 	else
// 	{
// 		printf("I'm a parent\n");
// 		printf("My parent pid: %d\n", getppid());
// 		printf("My pid: %d\n", getpid());
		

// 		child_pid = wait(&wstatus); // the only argument will be wstatus, and we will read pid of child process
// 		if (child_pid == -1)
// 		{
// 			perror("wait failed");
// 			exit(-1);
// 		}
// 		if (!WIFEXITED(wstatus))// check if child process ended normally, so the parent will also end
// 		{
// 			printf("child not exited\n");
// 			exit(0); 
// 		}
// 		printf("child %d returned %d\n", child_pid, WEXITSTATUS(wstatus));
// 		exit (0);
// 	}
// 	return (0);
// }



// int	main() // waiting for 1 kid
// {
// 	pid_t	pid;
// 	pid_t	child;
// 	int		wstatus;

// 	pid = fork();

// 	if (pid == 0)
// 	{
// 		printf("Child is finished\n");
// 		return (42);
// 	}

// 	child = wait(&wstatus);
// 	printf("Child PID=%d finished with code %d\n", child, WEXITSTATUS(wstatus));

// 	return (0);
// }


