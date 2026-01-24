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
	//printf("%d\n", value);
	printf("thread result: %p\n", result);

	return ((void *)result);
}

int main(int ac, char **av)
{
	pthread_t	th;
	int			*res;


	srand(time(NULL));
	
	if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
		return (1);

	if (pthread_join(th, (void **)&res) != 0)
		return (1);
	printf("main res: %p\n", res);
	printf("result: %d\n", *res);
	free(res);
	return (0);
}

