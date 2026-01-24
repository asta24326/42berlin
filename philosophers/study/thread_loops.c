#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int	mails = 0;
pthread_mutex_t	mutex;

void	*routine(void *arg)
{
	(void)arg;
	for (int i = 0; i < 10000000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int main(int ac, char **av)
{
	pthread_t	th[4];
	int			i;

	pthread_mutex_init(&mutex, NULL);
	for (i = 0; i < 4; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			return (1);
		printf("Thread: %d started\n", i);
		
	}
	// to make them work separately only when we don't wait them
	for (i = 0; i < 4; i++)
	{	
		if (pthread_join(th[i], NULL) != 0)
				return (2);
		printf("Thread: %d has finished execution\n", i);
	}
	// and here we actually don't see real time of finished execution
	// cus we're waiting for aech thread in array and only then joining them
	pthread_mutex_destroy(&mutex);

	printf("Number of mails: %d\n", mails);

	return (0);
}


// mutex - is lock around variable