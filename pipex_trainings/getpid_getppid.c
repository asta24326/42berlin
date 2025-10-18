#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	pid_t	pid;
	pid_t	ppid;

	pid = getpid();
	ppid = getppid();

	printf("My pid: %d\n", pid);
	printf("My ppid: %d\n", ppid);

	return (0);
}
