/*

Programm to work with open(), close(), write, read 

Basically imitating behaviour of cp system command

*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int	main(int argc, char **argv)
{
	char	*source;
	char	*dest;
	int		fd_in;
	int		fd_out;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	ssize_t	bytes_written;

	if (argc != 3)
	{
		printf("Please use: %s <source file> <dest file>\n", argv[0]);
		return (1);
	}

	source = argv[1];
	dest = argv[2];
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		return (perror("Error opening source file!\n"), 1);

	fd_out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 777);
	if (fd_out == -1)
		return (perror("Error creating destination file\n"), close(fd_in), 1);
	
	while ((bytes_read = read(fd_in, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_out, buffer, bytes_read);
		if (bytes_written == -1)
		{
			perror("Error writing to dest file\n");
			close(fd_in);
			close(fd_out);
			return (1);
		}
		if (bytes_written != bytes_read)
		{
			perror("Error: Written less than read!\n");
			close(fd_in);
			close(fd_out);
			return (1);
		}
	}

	if (bytes_read == -1)
	{
		perror("Error reading!\n");
		close(fd_in);
		close(fd_out);
		return (1);
	}

	close(fd_in);
	close(fd_out);

	printf("File successfully copied: %s -> %s!\n", source, dest);
	return (0);
}
