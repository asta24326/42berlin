#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t	mutexFuel;
pthread_cond_t	condFuel;
int	fuel = 0;

void	*fuel_filling(void *arg)
{
	for (int i = 0; i < 5; i++)
	{
		pthread_mutex_lock(&mutexFuel);
		fuel += 15;
		printf("Filling fuel... %d\n", fuel);
		pthread_mutex_unlock(&mutexFuel);
		pthread_cond_signal(&condFuel);// all the threads that are waiting for "condFuel"
										// are gonna continue execution
		sleep(1);
	}
		return (NULL);
}

void	*car(void *arg)
{
	pthread_mutex_lock(&mutexFuel); // we're locking mutex
	while (fuel < 40)
	{
		printf("No fuel. Waiting...\n");
		//sleep(1);
		pthread_cond_wait(&condFuel, &mutexFuel);// wait for a signal from other thread
												// actually we're unlocking mutexFuel and wait 
		// this function means next steps:
		// pthread_mutex_unlock(&mutexFuel) - unlock mutexFuel, to let fuel_filling to access fuel
		// wait for signal on condFuel var
		// pthread_mutex_lock(&mutexFuel) - and will lock again back

		// conditional var is or True or False and wait of condFuel does unlock mutex lock

	}
	fuel -= 40;
	printf("Got fuel. Now left: %d\n", fuel);
	pthread_mutex_unlock(&mutexFuel);
	return (NULL);
}


int main(int ac, char **av)
{
	pthread_t	th[2];
	
	pthread_mutex_init(&mutexFuel, NULL);
	pthread_cond_init(&condFuel, NULL);
	
	for (int i = 0; i < 2; i++)
	{
		if (i ==1)
		{
			if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0)
				perror("Error at creating thread");
		}
		else
		{
			if (pthread_create(&th[i], NULL, &car, NULL) != 0)
				perror("Error at creating thread");	
		}
	}
	for (int i = 0; i < 2; i++)
		if (pthread_join(th[i], NULL) != 0)
			perror ("Error joining thread");
	
	pthread_mutex_destroy(&mutexFuel);
	pthread_cond_destroy(&condFuel);

	return (0);
}

