#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet);

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	print_bits(2);
	return (1);
}

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char bit;

	i = 7;
	bit = 0;

	while (i >= 0)
	{
		bit = ((octet >> i) & 1) + 48;
		write (1, &bit, 1);
		i--;
	}
}
