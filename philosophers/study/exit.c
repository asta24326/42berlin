#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

void	*roll_dice(void *arg)
{
	int	value;
	int	*result;

	(void)arg;
	result = malloc(sizeof(int));
	value = (rand() % 6) + 1;
	*result = value;

	printf("Thread result: %d\n", value);

	//return ((void *)result);
	pthread_exit((void *) result);// the same as in main, but it could be killed if main process is completed
}

int main(int ac, char **av)
{
	pthread_t	th;
	int			*res;

	srand(time(NULL));

	if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
		return (1);

	pthread_exit(0); // it's gonna wait for all the threads
	if (pthread_join(th, (void **)&res) != 0) // here we would wait for the main thread to be done
		return (1);

	printf("main res: %p\n", res);
	printf("result: %d\n", *res);
	free(res);
	return (0);
}

