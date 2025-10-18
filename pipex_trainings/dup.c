/*

Programm to train dup() function

*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	main(void)
{
	int	fd_in;// creating test file
	int	copy;// to copy new fd
	char	buffer_1[100];
	char	buffer_2[100];

	// Opening for reading
	fd_in = open("test_for_dup.txt", O_RDONLY);
	printf("Original fd = %d\n", fd_in);
	
	//Duplicating
	copy = dup(fd_in);
	printf("Copy = %d\n", copy);

	//Reading from both
	read(fd_in, buffer_1, 10);

	read(copy, buffer_2, 10);

	printf("Original: '%s'\n", buffer_1);
	printf("Copy: '%s'\n", buffer_2);

	close(fd_in);	close(copy);
	return (0);
}
