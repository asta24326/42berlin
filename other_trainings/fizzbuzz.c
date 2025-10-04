#include <unistd.h>

void ft_putnbr(int i)
{
	char	c;
	long	lnb;

	lnb = i;
	if (lnb < 0)
	{
		write (1, "-", 1);
		lnb *= -1;
	}
	if (lnb >= 10)
		ft_putnbr(lnb / 10);
	c = (lnb % 10) + '0';
	write(1, &c, 1);
}

int main(void)
{
    int i;
    
    i = 1;
    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if  (i % 3 == 0)
            write(1, "fizz", 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else
            ft_putnbr(i);
        i++;
        write(1, "\n", 1);
    }
}