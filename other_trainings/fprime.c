#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	 main(int argc, char **argv)
{
	int	num;
	int	divisor;
	int	flag_first;

	if (argc == 2)
	{
		num = atoi(argv[1]);
		if (num <= 0)
			return (printf("\n"), 0);
		if (num == 1)
			return (printf("1\n"), 2);
		divisor = 2;//starting from smallest prior number
		flag_first = 1;//flag for the first prior number without '*'
		while (num > 1)
		{
			if (num % divisor == 0)
			{
				if (flag_first == 1)
					flag_first = 0;
				else
					printf("*");
				printf("%d", divisor);//printing out devisor
				num /= divisor;
			}
			else
			{
				//if there is no divisor, increasing it
				if (divisor == 2)
					divisor = 3;//skipping 2
				else
					divisor += 2;//trying next (5, 7, 9)
			}
		}
	}
	printf("\n");
	return(0);
}
