#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

int	main(void)
{
	int	fd;

	fd = open("dup2_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);

	ft_putstr_fd("1. Output to the screen\n", fd);

	printf("stdin fd = %i\n", STDIN_FILENO);
	printf("stdout fd = %i\n", STDOUT_FILENO);
	dup2(fd, 1); //dup2(<oldfd - what to copy>, <where to copy(if it's busy already, it will close previous and put new)>);


	ft_putnbr_fd(STDIN_FILENO, fd);
	write(1, "\n", fd);
	ft_putnbr_fd(STDOUT_FILENO, fd);
	write(1, "\n", fd);

	dup2(STDIN_FILENO, 1);

	// ft_putnbr_fd(STDIN_FILENO, fd);
	// write(1, "\n", fd);
	// ft_putnbr_fd(STDOUT_FILENO, fd);
	// write(1, "\n", fd);

	ft_putstr_fd("2. To the file!\n", fd);
	ft_putstr_fd("3. Also to the file!\n", fd);

	close(fd); // file  is closed
	//close(1); // stdout is closed

	ft_putstr_fd("4. Back to the sreen through fd!\n", fd);

	ft_putstr_fd("5. Back to the sreen thorugh 1!\n", 1);

	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}
void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	l_nbr;

	l_nbr = n;
	if (l_nbr < 0)
	{
		l_nbr *= -1;
		write(fd, "-", 1);
	}
	if (l_nbr >= 10)
		ft_putnbr_fd((l_nbr / 10), fd);
	c = (l_nbr % 10) + '0';
	write(fd, &c, 1);
}