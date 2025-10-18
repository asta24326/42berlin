#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	int	i;

	(void)argc;
	(void)argv;
	i = 0;
while (envp[i++])
	printf("Address: %p, Value: %s\n", (void *)envp[i], envp[i]);

	execve("/bin/ls", (char *const[]){"ls", "-l", NULL}, envp);
	perror("execve failed");
	return (1);
}

/*
char **envp - environment pointer - указатель на окружение
array of strings, containing enviroment variables, like PATH=/usr/bin:/bin of HOME=/home/user
		it passed from shell and used for process context configuration

execve - execute vector environment, system call that replaces current process with new one
		загружая и исполняя указанный исполняемый файл (in this case in /bin/ls).
		if successfully, then code after this command doesn't execute.

execve([full path to executed file of command /bin/ls], [array of pointers to strings])

(char	*const[]){"ls", "-l", NULL};
	ls - command name
	-l - argument for ls
	NULL - special character to end the string, so execve could understands where arguments are over
*/
