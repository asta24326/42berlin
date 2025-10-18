#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		pipes_fd[2];
	pid_t	pid;
	pid_t	pid2;

	fd = open("/tmp/here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	write(fd, "line1\nline2\n", 12);
	close(fd);

	printf("File is creted");

	pipe(pipes_fd); // now pipes_fd[0] -> fd(3) is for reading, pipes_fd[4] -> fd(4) for writing
	pid = fork();

	if (pid == 0) // child process
	{
		dup2("/tmp/here_doc", O_RDONLY, 0);
		dup2(pipes_fd[1], 1);
		execlp("cat", "cat", NULL);
	}

	pid2 = fork;

	if (pid == 0)
	{
		dup2()
	}
}
