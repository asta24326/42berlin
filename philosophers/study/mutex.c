#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t	mutex;

void	*function(void *arg)
{
	(void)arg;
	pthread_mutex_trylock(&mutex);

	printf("Got lock\n");
	sleep(1);

	pthread_mutex_unlock(&mutex);

	return (NULL);
}

int main(int ac, char **av)
{
	pthread_t	th[4];
	pthread_mutex_init(&mutex, NULL);

	for (int i = 0; i < 4; i++)
		if (pthread_create(&th[i], NULL, &function, NULL) != 0)
			perror("Error at creating thread");
	
	for (int i = 0; i < 4; i++)
		if (pthread_join(th[i], NULL) != 0)
			perror("Error joining thread");
	

	pthread_mutex_destroy(&mutex);

	return (0);
}

