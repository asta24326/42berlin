#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

int	primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*function(void *arg)
{
	int index = *(int *)arg;
	printf("%d \n", primes[index]);
	free(arg);
	return (NULL);
}

int main(int ac, char **av)
{
	pthread_t	th[10];
	
	
	for (int i = 0; i < 10; i++)
	{
		int *a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &function, a) != 0)
			perror("Failed to create thread");
	}
	for (int i = 0; i < 10; i++)
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
	
	return (0);
}

