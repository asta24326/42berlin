
#include <unistd.h>

void	put_str(char *str);

int	main(int argc, char *argv[])
{
	if (!argv[1][0])
		return (write(1, "\n", 1), 1);
	if (argc == 2)
		put_str(argv[1]);
	return (0);
}


void	put_str(char *str)
{
	int	i;
	int	repeat;

	i = 0;
	while (str[i])
	{
		repeat = 1;
		if (str[i] >= 'B' && str[i] <= 'Z')
				repeat = str[i] - ('A' - 1);
		if (str[i] >= 'b' && str[i] <= 'z')
				repeat = str[i] - ('a' - 1);
		while (repeat > 0)
		{
			write (1, &str[i], 1);
			repeat--;
		}
		i++;
	}
	write(1, "\n", 1);
}
