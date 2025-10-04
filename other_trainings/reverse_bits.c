#include <unistd.h>
#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet);
void	print_bits(unsigned char octet);

int	main(void)
{
	unsigned char c;

	c = 10;
	print_bits(c);
	print_bits(reverse_bits(c));
	return (1);
}

unsigned char	reverse_bits(unsigned char octet)
{
	int			i;
	unsigned char	result;

	i = 7;
	result = 0;
	while (i >= 0)
	{
		result = (result << 1) | (octet & 1);
		octet = octet >> 1;
		i--;
	}
	return (result);
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
	write(1, "\n", 1);
}
