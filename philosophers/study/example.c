#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void	*routine(void *arg)
{
	(void)arg;

	printf("test from threads\n");
	sleep(3); //3 secs
	printf("ending thread\n");
	return (NULL);
}

int main(int ac, char **av)
{
	pthread_t	t1;// struct
	pthread_t	t2;

	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);
	// [pointer to var] [customisation to threads] 
	// [function to be executed] [arguments to be passed to the function]
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (1);


	// next we need to wait for the execution

	// basically same as wait() for processes
	if (pthread_join(t1, NULL) != 0)
		return (1);
	if (pthread_join(t2, NULL) != 0)
		return (1);
	// [struct] [pointer that get's result from it]		


	return (0);
}
