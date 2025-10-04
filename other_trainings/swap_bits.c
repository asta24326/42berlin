#include <unistd.h>
#include <stdio.h>

unsigned char	swap_bits(unsigned char octet);
void			print_bits(unsigned char octet);

int	main(void)
{
	unsigned char	c;

	c = 10;
	print_bits(c);
	c = swap_bits(c);
	print_bits(c);
	return (1);
}

unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	temp;
	unsigned char	result;
	int				i;

	temp = octet << 4;
	octet = octet >> 4;
	return (result = octet | temp);
}

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	c;
		
	i = 7;
	c = 0;
	while (i >= 0)
	{
		c = ((octet >> i) & 1) + 48;
		write(1, &c, 1);
		i--;
	}
	write(1, "\n", 1);
}
