#include <pthread.h>
#include <stdio.h>




// with mutex we get 2000000 otherwise
// mutex protects the process
int mails = 0;
pthread_mutex_t mutex;

void *routine() {
	int i = 0;
	while(i < 1000000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
		i++;
	}
	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t p1, p2, p3;
	pthread_mutex_init(&mutex, NULL);
	if(pthread_create(&p1, NULL, &routine, NULL) != 0)
		return 1;
	if(pthread_create(&p2, NULL, &routine, NULL) != 0)
		return 2;
	if(pthread_create(&p3, NULL, &routine, NULL) != 0)
		return 5;
	if (pthread_join(p1, NULL) != 0)
		return 3;
	if (pthread_join(p2, NULL) != 0)
		return 4;
	if (pthread_join(p3, NULL) != 0)
		return 6;
	printf("number of mails %d\n", mails);
	return (0);
}
